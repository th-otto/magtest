/*
 * proto.h vom 23.06.1996
 *
 * Autor:
 * Thomas Binder
 * (binder@rbg.informatik.th-darmstadt.de)
 *
 * Zweck:
 * Enth�lt s�mtliche Prototypen und globale Variablen f�r das
 * Ramdisk-XFS und wird von ramdisk.h eingebunden.
 *
 * History:
 * 30.12.1995: Erstellung
 * 31.12.1995: Neuer Prototyp increase_refcnts.
 *             Prototyp von ramdisk_path2DD an neue Parameterform
 *             angepa�t.
 * 02.01.1996: uptonow beim Prototyp zu get_size entfernt.
 *             Im Prototyp getline size und mode vertauscht, weil es
 *             in der Pure-C-Schnittstelle verdreht definiert war.
 * 14.02.1996: Neue Prototypen read_infofile und readline.
 * 16.02.1996: Neuer Prototyp set_ramdisk_drive, Prototyp von
 *             read_infofile ver�ndert.
 * 17.02.1996: Neue Variable eight_bit.
 * 26.02.1996: Neue Variable volume_label.
 * 23.04.1996: Neuer Prototyp get_cookie.
 * 23.06.1996: Neue Prototypen Pdomain_gemdos, Pdomain_kernel,
 *             Mxalloc_kernel und Mfree_kernel, neue Variablen
 *             Pdomain, _Mxalloc und _Mfree
 */

#ifndef _RAMDISK_PROTO_H
#define _RAMDISK_PROTO_H

/* Prototypen */
void read_infofile(void);
WORD readline(WORD handle, char *buffer);
LONG get_and_set_drive(void);
LONG set_ramdisk_drive(void);
void increase_refcnts(RAMDISK_FD *dd);
LONG attrib_action(DIRENTRY *entry, LONG rwflag, LONG attrib);
LONG chmod_action(DIRENTRY *entry, LONG _mode, LONG dummy);
LONG get_size(DIRENTRY *search);
LONG dcntl_action(DIRENTRY *entry, LONG cmd, LONG arg);

LONG ramdisk_sync(DMD *d);
void ramdisk_pterm(BASPAG *pd);
LONG ramdisk_garbcoll(DMD *d);
void ramdisk_freeDD(void *dd);
LONG ramdisk_drv_open(DMD *d);
LONG ramdisk_drv_close(DMD *d, WORD mode);
LONG ramdisk_path2DD(void *reldir, char *pathname, WORD mode,
	char **lastpath, LONG *linkdir, char **symlink);
LONG ramdisk_sfirst(void *srchdir, char *name, DTA *dta,
	WORD attrib, char **symlink);
LONG ramdisk_snext(DTA *dta, DMD *dmd, char **symlink);
LONG ramdisk_fopen(void *dir, char *name, WORD omode, WORD attrib,
	char **symlink);
LONG ramdisk_fdelete(void *dir, char *name);
LONG ramdisk_link(void *olddir, void *newdir, char *oldname,
	char *newname, WORD flag_link);
LONG ramdisk_xattr(void *dir, char *name, XATTR *xattr, WORD mode,
	char **symlink);
LONG ramdisk_attrib(void *dir, char *name, WORD rwflag, WORD attrib,
	char **symlink);
LONG ramdisk_chown(void *dir, char *name, UWORD uid, UWORD gid,
	char **symlink);
LONG ramdisk_chmod(void *dir, char *name, UWORD mode,
	char **symlink);
LONG ramdisk_dcreate(void *dir, char *name);
LONG ramdisk_ddelete(void *dir);
LONG ramdisk_DD2name(void *dir, char *name, WORD bufsize);
LONG ramdisk_dopendir(void *dir, WORD tosflag);
LONG ramdisk_dreaddir(void *dhd, WORD size, char *buf, XATTR *xattr,
	LONG *xr);
LONG ramdisk_drewinddir(void *dhd);
LONG ramdisk_dclosedir(void *dhd);
LONG ramdisk_dpathconf(void *dir, WORD which);
LONG ramdisk_dfree(void *dd, DISKINFO *free);
LONG ramdisk_wlabel(void *dir, char *name);
LONG ramdisk_rlabel(void *dir, char *name, char *buf, WORD len);
LONG ramdisk_symlink(void *dir, char *name, char *to);
LONG ramdisk_readlink(void *dir, char *name, char *buf, WORD size);
LONG ramdisk_dcntl(void *dir, char *name, WORD cmd, LONG arg,
	char **symlink);

LONG ramdisk_close(void *file);
LONG ramdisk_read(void *file, LONG count, char *buffer);
LONG ramdisk_write(void *file, LONG count, char *buffer);
LONG ramdisk_stat(void *file, MAGX_UNSEL *unselect, WORD rwflag,
	LONG apcode);
LONG ramdisk_seek(void *file, LONG where, WORD mode);
LONG ramdisk_datime(void *file, WORD *d, WORD setflag);
LONG ramdisk_ioctl(void *file, WORD cmd, void *buf);
LONG ramdisk_getc(void *file, WORD mode);
LONG ramdisk_getline(void *file, char *buf, WORD mode, LONG size);
LONG ramdisk_putc(void *file, WORD mode, LONG value);

void prepare_dir(DIRENTRY *dir, WORD maxentries, DIRENTRY *parent);
DIRENTRY *findfile(RAMDISK_FD *dd, const char *pathname, WORD spos,
	WORD s_or_e, WORD maybe_dir);
#define FF_SEARCH	0
#define FF_EXIST	1
RAMDISK_FD *findfd(DIRENTRY *fname);
DIRENTRY *new_file(RAMDISK_FD *curr, const char *name);
WORD dir_is_open(DIRENTRY *dir);
WORD check_name(const char *name);
LONG check_dd(RAMDISK_FD *dd);
LONG check_fd(RAMDISK_FD *fd);
LONG work_entry(RAMDISK_FD *dd, const char *name, char **symlink,
	WORD writeflag, LONG par1, LONG par2,
	LONG (*action)(DIRENTRY *entry, LONG par1, LONG par2));
LONG set_amtime(DIRENTRY *entry, LONG set_atime, LONG unused);
void tostrunc(char *dest, const char *src, WORD wildcards);
void fill_tosname(char *dest, char *src);
WORD match_tosname(char *to_check, char *sample);
WORD has_xext(const char *name);
void *Kmalloc(LONG len);
void *Krealloc(void *ptr, LONG old_len, LONG new_len);
LONG Pdomain_gemdos(WORD domain);
LONG Pdomain_kernel(WORD ignore);
void *Mxalloc_kernel(LONG amount, WORD mode);
WORD Mfree_kernel(void *block);
#ifdef DEBUG
void trace(const char *format, ...);
#define TRACE(x) trace x
#else
#define TRACE(x)
#endif
WORD get_cookie(ULONG cookie, ULONG *value);

/*
 * Globale Variablen, die entweder "extern" oder direkt deklariert
 * bzw. definiert werden.
 */
extern THE_MX_KERNEL *kernel;
#ifdef ONLY_EXTERN
#define _GLOBAL	extern
_GLOBAL	THE_MGX_XFS	ramdisk_xfs;
_GLOBAL THE_MGX_DEV	ramdisk_dev;
#else
#define _GLOBAL
THE_MGX_XFS		ramdisk_xfs = {
	"Ramdisk", ramdisk_sync, ramdisk_pterm, ramdisk_garbcoll,
	ramdisk_freeDD, ramdisk_drv_open, ramdisk_drv_close,
	ramdisk_path2DD, ramdisk_sfirst, ramdisk_snext, ramdisk_fopen,
	ramdisk_fdelete, ramdisk_link, ramdisk_xattr, ramdisk_attrib,
	ramdisk_chown, ramdisk_chmod, ramdisk_dcreate, ramdisk_ddelete,
	ramdisk_DD2name, ramdisk_dopendir, ramdisk_dreaddir,
	ramdisk_drewinddir, ramdisk_dclosedir, ramdisk_dpathconf,
	ramdisk_dfree, ramdisk_wlabel, ramdisk_rlabel, ramdisk_symlink,
	ramdisk_readlink, ramdisk_dcntl};
THE_MGX_DEV		ramdisk_dev = {
	ramdisk_close, ramdisk_read, ramdisk_write, ramdisk_stat,
	ramdisk_seek, ramdisk_datime, ramdisk_ioctl, ramdisk_getc,
	ramdisk_getline, ramdisk_putc};
#endif
_GLOBAL	WORD			ramdisk_drive,
						starttime,
						startdate;
_GLOBAL	DMD				*ramdisk_dmd;
_GLOBAL	RAMDISK_FD		fd[MAX_FD];
_GLOBAL	RAMDISK_DHD		dhd[MAX_DHD];
_GLOBAL	DIRENTRY		root[ROOTSIZE],
						root_de;
_GLOBAL	LONG			leave_free;
_GLOBAL	WORD			ram_type,
						eight_bit;
_GLOBAL char			volume_label[34];
_GLOBAL LONG			(*p_Pdomain)(WORD ignore);
_GLOBAL void			*(*_Mxalloc)(LONG amount, WORD mode);
_GLOBAL WORD			(*_Mfree)(void *block);
#ifdef DEBUG
_GLOBAL	WORD			debug_to_screen;
#endif

#endif /* _RAMDISK_PROTO_H */

/* EOF */
