// 
// Tests for generating ABI library functions
// Include all (almost all?) files from /usr/include
//
// TODO: automate running this :)
//

#define _GNU_SOURCE 1
#define _REGEX_RE_COMP
#define _BSD_SOURCE 1

// needed to handle gets since it is deprecated
extern char *gets(char *s); 

#include <nfs/nfs.h>
#include <mcheck.h>
#include <features.h>
#include <dlfcn.h>
#include <unistd.h>
#include <argp.h>
#include <neteconet/ec.h>
#include <netinet/ip_icmp.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/ether.h>
#include <netinet/in_systm.h>
#include <netinet/tcp.h>
#include <netinet/if_tr.h>
#include <netinet/icmp6.h>
#include <netinet/igmp.h>
#include <netinet/if_fddi.h>
#include <wordexp.h>
#include <tgmath.h>
#include <complex.h>
#include <netatalk/at.h>
#include <ar.h>
#include <rpcsvc/spray.h>
#include <rpcsvc/nis_tags.h>
#include <rpcsvc/klm_prot.h>
#include <rpcsvc/sm_inter.h>
#include <rpcsvc/nlm_prot.h>
#include <rpcsvc/nis.h>
#include <rpcsvc/nis_callback.h>
//#include <rpcsvc/yppasswd.h>
#include <rpcsvc/key_prot.h>
#include <rpcsvc/rusers.h>
#include <rpcsvc/nislib.h>
#include <rpcsvc/ypclnt.h>
#include <rpcsvc/rex.h>
#include <rpcsvc/mount.h>
#include <rpcsvc/bootparam.h>
#include <rpcsvc/ypupd.h>
#include <rpcsvc/rstat.h>
//#include <rpcsvc/yp.h>
//#include <rpcsvc/nfs_prot.h>
#include <rpcsvc/rquota.h>
//#include <rpcsvc/yp_prot.h>
#include <rpcsvc/bootparam_prot.h>
#include <netipx/ipx.h>
#include <_G_config.h>
#include <libio.h>
#include <strings.h>
#include <nss.h>
#include <netrom/netrom.h>
#include <malloc.h>
#include <x86_64-linux-gnu/ieee754.h>
#include <x86_64-linux-gnu/sys/timerfd.h>
#include <x86_64-linux-gnu/sys/timeb.h>
#include <x86_64-linux-gnu/sys/unistd.h>
#include <x86_64-linux-gnu/sys/debugreg.h>
#include <x86_64-linux-gnu/sys/utsname.h>
#include <x86_64-linux-gnu/sys/ioctl.h>
#include <x86_64-linux-gnu/sys/reg.h>
#include <x86_64-linux-gnu/sys/socketvar.h>
#include <x86_64-linux-gnu/sys/sysinfo.h>
#include <x86_64-linux-gnu/sys/socket.h>
#include <x86_64-linux-gnu/sys/poll.h>
#include <x86_64-linux-gnu/sys/vt.h>
#include <x86_64-linux-gnu/sys/uio.h>
#include <x86_64-linux-gnu/sys/msg.h>
#include <x86_64-linux-gnu/sys/stat.h>
#include <x86_64-linux-gnu/sys/klog.h>
#include <x86_64-linux-gnu/sys/termios.h>
#include <x86_64-linux-gnu/sys/ipc.h>
#include <x86_64-linux-gnu/sys/mtio.h>
#include <x86_64-linux-gnu/sys/ttychars.h>
#include <x86_64-linux-gnu/sys/select.h>
//#include <x86_64-linux-gnu/sys/ultrasound.h>
#include <x86_64-linux-gnu/sys/times.h>
#include <x86_64-linux-gnu/sys/un.h>
#include <x86_64-linux-gnu/sys/eventfd.h>
#include <x86_64-linux-gnu/sys/xattr.h>
#include <x86_64-linux-gnu/sys/fanotify.h>
#include <x86_64-linux-gnu/sys/statvfs.h>
#include <x86_64-linux-gnu/sys/shm.h>
#include <x86_64-linux-gnu/sys/resource.h>
#include <x86_64-linux-gnu/sys/raw.h>
#include <x86_64-linux-gnu/sys/syslog.h>
#include <x86_64-linux-gnu/sys/syscall.h>
#include <x86_64-linux-gnu/sys/epoll.h>
#include <x86_64-linux-gnu/sys/quota.h>
#include <x86_64-linux-gnu/sys/ptrace.h>
#include <x86_64-linux-gnu/sys/stropts.h>
#include <x86_64-linux-gnu/sys/cdefs.h>
#include <x86_64-linux-gnu/sys/personality.h>
#include <x86_64-linux-gnu/sys/dir.h>
#include <x86_64-linux-gnu/sys/swap.h>
#include <x86_64-linux-gnu/sys/user.h>
#include <x86_64-linux-gnu/sys/ucontext.h>
#include <x86_64-linux-gnu/sys/bitypes.h>
#include <x86_64-linux-gnu/sys/vtimes.h>
#include <x86_64-linux-gnu/sys/gmon_out.h>
#include <x86_64-linux-gnu/sys/signal.h>
#include <x86_64-linux-gnu/sys/fcntl.h>
#include <x86_64-linux-gnu/sys/prctl.h>
#include <x86_64-linux-gnu/sys/inotify.h>
#include <x86_64-linux-gnu/sys/kd.h>
#include <x86_64-linux-gnu/sys/errno.h>
#include <x86_64-linux-gnu/sys/profil.h>
#include <x86_64-linux-gnu/sys/acct.h>
#include <x86_64-linux-gnu/sys/sem.h>
#include <x86_64-linux-gnu/sys/perm.h>
#include <x86_64-linux-gnu/sys/signalfd.h>
#include <x86_64-linux-gnu/sys/sysmacros.h>
#include <x86_64-linux-gnu/sys/param.h>
#include <x86_64-linux-gnu/sys/reboot.h>
//#include <x86_64-linux-gnu/sys/kdaemon.h>
#include <x86_64-linux-gnu/sys/auxv.h>
#include <x86_64-linux-gnu/sys/file.h>
#include <x86_64-linux-gnu/sys/sysctl.h>
#include <x86_64-linux-gnu/sys/wait.h>
#include <x86_64-linux-gnu/sys/mman.h>
#include <x86_64-linux-gnu/sys/mount.h>
#include <x86_64-linux-gnu/sys/sendfile.h>
#include <x86_64-linux-gnu/sys/soundcard.h>
#include <x86_64-linux-gnu/sys/ttydefaults.h>
#include <x86_64-linux-gnu/sys/gmon.h>
#include <x86_64-linux-gnu/sys/fsuid.h>
#include <x86_64-linux-gnu/sys/procfs.h>
#include <x86_64-linux-gnu/sys/timex.h>
#include <x86_64-linux-gnu/sys/vfs.h>
#include <x86_64-linux-gnu/sys/queue.h>
#include <x86_64-linux-gnu/sys/statfs.h>
#include <x86_64-linux-gnu/sys/pci.h>
#include <x86_64-linux-gnu/sys/types.h>
#include <x86_64-linux-gnu/sys/io.h>
#include <x86_64-linux-gnu/sys/ustat.h>
#include <x86_64-linux-gnu/sys/vlimit.h>
#include <x86_64-linux-gnu/sys/time.h>
#include <x86_64-linux-gnu/a.out.h>
#include <x86_64-linux-gnu/gnu/stubs.h>
#include <x86_64-linux-gnu/gnu/stubs-64.h>
#include <x86_64-linux-gnu/gnu/libc-version.h>
//#include <x86_64-linux-gnu/gnu/option-groups.h>
#include <x86_64-linux-gnu/gnu/lib-names.h>
#include <x86_64-linux-gnu/fpu_control.h>
#include <string.h>
#include <poll.h>
#include <locale.h>
#include <protocols/rwhod.h>
#include <protocols/routed.h>
#include <protocols/talkd.h>
#include <protocols/timed.h>
#include <utime.h>
#include <netrose/rose.h>
#include <dirent.h>
#include <gconv.h>
#include <ifaddrs.h>
#include <pty.h>
#include <limits.h>
#include <net/ppp_defs.h>
#include <net/if_arp.h>
#include <net/if_slip.h>
#include <net/if_packet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <net/if_ppp.h>
#include <net/ppp-comp.h>
#include <net/route.h>
#include <net/if_shaper.h>
#include <termios.h>
#include <mqueue.h>
#include <glob.h>
#include <resolv.h>
#include <netpacket/packet.h>
#include <obstack.h>
#include <sysexits.h>
#include <setjmp.h>
#include <ttyent.h>
#include <utmp.h>
#include <fnmatch.h>
#include <arpa/tftp.h>
#include <arpa/ftp.h>
#include <arpa/inet.h>
#include <arpa/telnet.h>
#include <arpa/nameser.h>
#include <arpa/nameser_compat.h>
#include <memory.h>
#include <syslog.h>
#include <uchar.h>
#include <syscall.h>
#include <stdint.h>
#include <paths.h>
#include <assert.h>
#include <fmtmsg.h>
#include <endian.h>
#include <stropts.h>
#include <values.h>
#include <crypt.h>
#include <xlocale.h>
#include <stdio.h>
#include <stdlib.h>
#include <sgtty.h>
#include <ucontext.h>
#include <spawn.h>
#include <signal.h>
#include <stab.h>
#include <thread_db.h>
#include <cpio.h>
#include <fcntl.h>
#include <printf.h>
#include <monetary.h>
#include <mntent.h>
//#include <regexp.h>
#include <langinfo.h>
#include <regex.h>
#include <re_comp.h>
#include <lastlog.h>
#include <ctype.h>
#include <semaphore.h>
#include <argz.h>
#include <errno.h>
#include <scsi/scsi_ioctl.h>
#include <scsi/scsi.h>
#include <scsi/sg.h>
#include <libintl.h>
#include <wctype.h>
#include <netash/ash.h>
#include <gnu-versions.h>
#include <pthread.h>
#include <alloca.h>
#include <fenv.h>
#include <getopt.h>
#include <pwd.h>
#include <execinfo.h>
#include <fstab.h>
#include <link.h>
#include <ftw.h>
#include <netdb.h>
#include <wchar.h>
#include <libgen.h>
#include <sched.h>
#include <gshadow.h>
#include <rpc/des_crypt.h>
#include <rpc/xdr.h>
#include <rpc/auth_des.h>
#include <rpc/pmap_prot.h>
#include <rpc/pmap_rmt.h>
#include <rpc/svc_auth.h>
#include <rpc/pmap_clnt.h>
#include <rpc/key_prot.h>
#include <rpc/rpc_msg.h>
#include <rpc/clnt.h>
#include <rpc/netdb.h>
#include <rpc/rpc.h>
#include <rpc/svc.h>
#include <rpc/auth_unix.h>
#include <rpc/rpc_des.h>
#include <rpc/types.h>
#include <rpc/auth.h>
#include <wait.h>
#include <shadow.h>
#include <utmpx.h>
#include <stdio_ext.h>
#include <iconv.h>
#include <netiucv/iucv.h>
#include <error.h>
#include <envz.h>
#include <termio.h>
#include <search.h>
#include <math.h>
#include <aio.h>
#include <stdc-predef.h>
#include <ulimit.h>
#include <grp.h>
#include <byteswap.h>
#include <nl_types.h>
#include <inttypes.h>
#include <aliases.h>
#include <elf.h>
#include <tar.h>
#include <fts.h>
#include <ustat.h>
#include <time.h>
#include <err.h>
#include <netax25/ax25.h>
