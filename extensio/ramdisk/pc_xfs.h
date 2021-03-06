/*
 * pc_xfs.h vom 23.06.1996
 *
 * Autor:
 * Thomas Binder
 * (binder@rbg.informatik.th-darmstadt.de)
 *
 * Zweck:
 * Headerdatei f�r die Pure-C-MagiC-3-XFS-Schnittstelle. Die genau
 * Beschreibung der Funktionen entnehme man der MagiC-3-Doku, die f�r
 * registrierte Benutzer bei ASH erh�ltlich ist. Hier finden sich nur
 * Erkl�rungen f�r die Unterschiede zwischen der Beschreibung in der
 * Doku und den benutzten Funktionspointern, die sich aus technischen
 * Gr�nden leider nicht vermeiden lie�en.
 *
 * History:
 * 04.11.-
 * 05.11.1995: Erstellung
 * 06.11.1995: MX_KERNEL in THE_MX_KERNEL umbenannt, da sich gezeigt
 *             hat, da� die darin erreichbaren Funktionen Register A2
 *             ver�ndern, was Pure C gewaltig in's Schleudern bringt.
 *             Daher mu�te auch diese Struktur auf eine eigene
 *             interne abgebildet werden, in der die Funktionen die
 *             Register vorher retten und dann die eigentlich
 *             gew�nschte Routine anspringen (siehe pc_xfs.s).
 * 07.11.1995: XATTR-Struktur kommentiert und mit Konstanten versehen
 * 10.11.1995: mode bei xfs_dcreate entfernt, da es in der neuen
 *             MagiC-3-Doku nicht mehr auftaucht.
 * 11.11.1995: _sprintf in der Kernel-Struktur ist nicht mehr cdecl,
 *             da ja sowieso eine vorgeschaltete Routine angesprungen
 *             wird, die dann die Parameter auf den Stack legt.
 * 12.11.1995: xfs_fopen, xfs_xattr und xfs_attrib m�ssen bei Bedarf
 *             auch einen Zeiger auf einen symbolischen Link liefern,
 *             daher wurde bei den Prototypen ein solcher eingebaut.
 * 23.11.1995: dta_drive war versehentlich WORD statt char.
 * 11.12.1995: Erweiterung der THE_MX_KERNEL-Struktur um die neuen
 *             Elemente von Kernelversion 1 und 2.
 * 26.12.1995: KER_INSTXFS und KER_GETINFO aufgenommen.
 * 28.12.1995: Auch xfs_chmod, xfs_chown und xfs_dcntl m�ssen u.U.
 *             einen Zeiger auf einen symbolischen Link liefern,
 *             daher wurden die Prototypen entsprechend erweitert.
 * 31.12.1995: path2DD hat jetzt kein unhandliches returns-Array
 *             mehr, sondern die neuen Einzelparameter lastpath,
 *             linkdir und symlink.
 * 02.01.1996: Bei dev_getline waren mode und size vertauscht.
 * 13.02.1996: Der zweite Parameter f�r install_xfs war unn�tig und
 *             ist deswegen jetzt 'rausgeflogen, ebenso wie der
 *             Zeiger real_dev.
 * 16.06.1996: d_devcode in der Struktur DMD war vom falschen Typ.
 * 23.06.1996: Neue Elemente mxalloc, mfree und mshrink in die
 *             Kernelstruktur aufgenommen.
 */

#ifndef __PC_XFS__
#define __PC_XFS__

#include <tos.h>
#include <portab.h>
#include <sys/stat.h>
#include "toserror.h"
#define PD BASEPAGE
typedef void APPL;
#include "mgx_xfs.h"

/*
 * Zeiger auf die tats�chlich von MagiC angesprochenen Strukturen.
 * Sie werden u.a. bei xfs_drv_open und bei xfs_fopen ben�tigt, denn
 * es darf nat�rlich nie der Zeiger auf die C-Struktur eingetragen
 * werden, wenn es sich um MagiC-Strukturen wie DMD, DD, FD, oder DHD
 * handelt.
 */
extern MX_XFS my_xfs;


/*
 * Die XFS-Schnittstelle, wie sie das C-Programm sieht. In dieser
 * Struktur fehlen die Anteile der XFS-Schnittstelle, die f�r
 * (externe) Treiber ohne Belang sind.
 */
typedef struct _the_mgx_xfs
{
	char	xfs_name[8];
	struct _the_mgx_xfs *xfs_next;
	ULONG   xfs_flags;
	long    (*xfs_init)(void);
	void	(*xfs_sync)(MX_DMD *d);
	void	(*xfs_pterm)(MX_DMD *d, PD *pd);
/*
 * F�r xfs_garbcoll mu� ein Funktionspointer angegeben werden, auch
 * wenn das Filesystem die interne Speicherverwaltung von MagiC 3
 * nicht benutzt. In diesem Fall einfach eine Funktion einbinden, die
 * 0L zur�ckliefert.
 */
	LONG	(*xfs_garbcoll)(MX_DMD *d);
	void	(*xfs_freeDD)(MX_DD *dd);
	LONG	(*xfs_drv_open)(MX_DMD *d);
	LONG	(*xfs_drv_close)(MX_DMD *d, WORD mode);
/*
 * Da xfs_path2DD normalerweise bis zu vier R�ckgabewerte hat, werden
 * drei davon in Zeigerparametern zur�ckgegeben. Die Zuordnung der
 * Register (siehe MagiC-3-Doku):
 * d0: R�ckgabewert der C-Funktion
 * d1: *lastpath
 * a0: *linkdir
 * a1: *symlink
 */
	LONG	(*xfs_path2DD)(MX_DD *reldir, const char *pathname, WORD mode,
		const char **lastpath, MX_DD **linkdir, void **symlink);
/*
 * Auch xfs_sfirst liefert zwei R�ckgabeparameter. Da a0 aber nur
 * einen Zeiger auf einen Symbolischen Link enthalten kann, ist der
 * Parameter entsprechend als char ** deklariert, d.h. die C-Funktion
 * mu� ggf. hier den Zeiger auf den symbolischen Link ablegen (dabei
 * nicht vergessen, da� die ersten beiden "Buchstaben" die L�nge des
 * Links (als Wort) angeben).
 */
	LONG	(*xfs_sfirst)(MX_DD *srchdir, const char *name, DTA *dta,
		WORD attrib, void **symlink);
/* Entsprechendes gilt nat�rlich auch f�r xfs_snext */
	LONG	(*xfs_snext)(DTA *dta, MX_DMD *dmd, void **symlink);
#define OM_RPERM	1
#define OM_WPERM	2
#define OM_EXEC		4
#define OM_APPEND	8
#define OM_RDENY	16
#define OM_WDENY	32
#define OM_NOCHECK	64
/*
 * Dont get fooled by Pure-C header files;
 * we need the MiNT values here
 */
#undef O_CREAT
#undef O_TRUNC
#undef O_EXCL
#define O_CREAT		0x200
#define O_TRUNC		0x400
#define O_EXCL		0x800
/*
 * Auch xfs_fopen liefert unter Umst�nden einen Zeiger auf einen
 * symbolischen Link...
 */
	LONG	(*xfs_fopen)(MX_DD *dir, const char *name, WORD omode,
		WORD attrib, void **symlink);
	LONG	(*xfs_fdelete)(MX_DD *dir, const char *name);
	LONG	(*xfs_link)(MX_DD *olddir, MX_DD *newdir, const char *oldname,
		const char *newname, WORD flag_link);
/* Ebenfalls zus�tzlich mit Platzhalter f�r symbolischen Link */
	LONG	(*xfs_xattr)(MX_DD *dir, const char *name, XATTR *xattr,
		WORD mode, void **symlink);
/* Und noch dreimal... */
	LONG	(*xfs_attrib)(MX_DD *dir, const char *name, WORD rwflag,
		WORD attrib, void **symlink);
	LONG	(*xfs_chown)(MX_DD *dir, const char *name, UWORD uid,
		UWORD gid, void **symlink);
	LONG	(*xfs_chmod)(MX_DD *dir, const char *name, UWORD mode,
		void **symlink);
	LONG	(*xfs_dcreate)(MX_DD *dir, const char *name, UWORD mode);
	LONG	(*xfs_ddelete)(MX_DD *dir);
	LONG	(*xfs_DD2name)(MX_DD *dir, char *name, WORD bufsize);
	LONG	(*xfs_dopendir)(MX_DD *dir, WORD tosflag);
	LONG	(*xfs_dreaddir)(MX_DHD *dhd, WORD size, char *buf,
		XATTR *xattr, LONG *xr);
	LONG	(*xfs_drewinddir)(MX_DHD *dhd);
	LONG	(*xfs_dclosedir)(MX_DHD *dhd);
	LONG	(*xfs_dpathconf)(MX_DD *dir, WORD which);
	LONG	(*xfs_dfree)(MX_DD *dd, DISKINFO *free);
	LONG	(*xfs_wlabel)(MX_DD *dir, const char *name);
	LONG	(*xfs_rlabel)(MX_DD *dir, const char *name, char *buf,
		WORD len);
	LONG	(*xfs_symlink)(MX_DD *dir, const char *name, const char *to);
	LONG	(*xfs_readlink)(MX_DD *dir, const char *name, char *buf,
		WORD size);
/* Nochmal mit Platzhalter f�r symbolischen Link */
	LONG	(*xfs_dcntl)(MX_DD *dir, const char *name, WORD cmd, LONG arg,
		void **symlink);
} THE_MGX_XFS;

/*
 * Der Devicetreiber ist identisch mit der
 * "echten" Struktur, d.h. hier sind keine vorgeschalteten
 * Assemblerroutinen n�tig
 */

/*
 * Zeiger auf die tats�chlich von Dcntl(KER_INSTXFS, ...) gelieferte
 * Kernelstruktur. Die Funktionen sollten nicht angesprochen werden,
 * f�r das Auslesen der Variablen ist es jedoch ratsam, immer �ber
 * diese Struktur zu gehen, da die Kopie nicht aktualisiert wird.
 */
extern MX_KERNEL *real_kernel;

/*
 * Die Kernel-Struktur, deren Funktionen leider auch nicht direkt von
 * Pure C aus aufgerufen werden k�nnen, da sie unter Umst�nden das
 * Register A2 ver�ndern, was Pure C �berhaupt nicht mag. Also wird
 * diese Struktur ebenfalls nachgebildet... Um die Variablen aus der
 * Struktur anzusprechen empfiehlt es sich, den Zeiger real_kernel
 * zu benutzen, da die Kopie nicht aktualisiert wird und es durchaus
 * denkbar ist, da� einer der Variablenzeiger nachtr�glich ge�ndert
 * wird. Die vorgeschalteten Funktionen benutzen selbstverst�ndlich
 * auch real_kernel, um die tats�chlich gew�nschten Routinen
 * aufzurufen.
 */
extern MX_KERNEL *kernel;
extern MX_KERNEL *install_kernel(MX_KERNEL *);

/*
 * Routine zur Installation des XFS. Ihr �bergibt man den Zeiger auf
 * das zu installierende XFS. Zur�ck erh�lt man einen Zeiger auf die
 * Kernelstruktur von MagiC 3 oder NULL, wenn ein Fehler aufgetreten
 * ist.
 */
LONG install_xfs(THE_MGX_XFS *xfs);

#endif

/* EOF */
