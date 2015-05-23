
/* ftpmap.h - the FTP-Map project header */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <signal.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

#define MAX_STR 256
#define MAX_ANSWER  1024
#define FTP_CRLF    "\x0a\x0d"
#define FTP_DEFAULT_SERVER  "localhost"
#define FTP_DEFAULT_PORT    "21"
#define FTP_DEFAULT_USER    "Anonymous"
#define FTP_DEFAULT_PASSWORD    "hello@"

const char ftpmap_ascii[] = 
"\x0a"
"\t███████╗████████╗██████╗ ███╗   ███╗ █████╗ ██████╗ \n"
"\t██╔════╝╚══██╔══╝██╔══██╗████╗ ████║██╔══██╗██╔══██╗\n"
"\t█████╗     ██║   ██████╔╝██╔████╔██║███████║██████╔╝\n"
"\t██╔══╝     ██║   ██╔═══╝ ██║╚██╔╝██║██╔══██║██╔═══╝ \n"
"\t██║        ██║   ██║     ██║ ╚═╝ ██║██║  ██║██║     \n"
"\t╚═╝        ╚═╝   ╚═╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝     \n"
"                     FTP Scanner.                     \n";

int fd;

typedef struct {
    FILE *fid;
    char ip_addr[MAX_STR];
    char *answer;
    char *server;
    char *port;
    char *user;
    char *password;
    char *cmd;
    int skip_fingerprint;
 } ftpmap_t;

typedef struct {
    char fversion[MAX_STR];
    char fsoftware[MAX_STR];
    char software[MAX_STR];
    char version[MAX_STR];
    char fisoftware[MAX_STR];
} detect_t;

typedef struct {
    char exploit[MAX_STR];
    int id;
} exploit_t;

void ftpmap_detect_version_by_banner(ftpmap_t*,detect_t*);
void ftpmap_init(ftpmap_t*);
void ftpmap_reconnect(ftpmap_t*);
void print_usage(int);
void print_version(int);
void sigalrm(int);
