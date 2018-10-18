/* Aus STD */

extern size_t strlen(const char *string);
extern int strcmp(const char *s1, const char *s2);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
extern int stricmp(const char *s1, const char *s2);
extern void vstrcpy(char *dst, const char *src);
extern void vmemcpy(void *dst, void *src, UWORD len);
extern void fast_clrmem(void *von, void *bis);
extern void ext_8_3(char *dst_name, char *src_int_name);
extern void int_8_3(char *dst_int_name, char *src_name);
extern char toupper(char c);

LONG smalloc( ULONG size);
void smfree( void *memblk );
LONG mmalloc( ULONG size);
void mfree( void *memblk );
LONG mshrink( void *memblk, ULONG size);
WORD dgetdrv( void );
LONG dopendir( char *path, WORD tosflag );
LONG dclosedir( LONG dirhandle );
LONG dxreaddir( WORD len, LONG dirhandle, char *buf,
			XATTR *xattr, LONG *xr );
LONG drvmap( void );
LONG fxattr( WORD mode, char *path, XATTR *xattr );
LONG dgetpath( char *buf, WORD drv );
LONG dpathconf(char *path, WORD which);