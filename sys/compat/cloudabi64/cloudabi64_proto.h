/*
 * System call prototypes.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

#ifndef _CLOUDABI64_SYSPROTO_H_
#define	_CLOUDABI64_SYSPROTO_H_

#include <sys/signal.h>
#include <sys/acl.h>
#include <sys/cpuset.h>
#include <sys/domainset.h>
#include <sys/_ffcounter.h>
#include <sys/_semaphore.h>
#include <sys/ucontext.h>
#include <sys/wait.h>

#include <bsm/audit_kevents.h>

#include <sys/mach/mach_types.h>

struct proc;

struct thread;

#define	PAD_(t)	(sizeof(register_t) <= sizeof(t) ? \
		0 : sizeof(register_t) - sizeof(t))

#if BYTE_ORDER == LITTLE_ENDIAN
#define	PADL_(t)	0
#define	PADR_(t)	PAD_(t)
#else
#define	PADL_(t)	PAD_(t)
#define	PADR_(t)	0
#endif

struct cloudabi_sys_clock_res_get_args {
	char clock_id_l_[PADL_(cloudabi_clockid_t)]; cloudabi_clockid_t clock_id; char clock_id_r_[PADR_(cloudabi_clockid_t)];
};
struct cloudabi_sys_clock_time_get_args {
	char clock_id_l_[PADL_(cloudabi_clockid_t)]; cloudabi_clockid_t clock_id; char clock_id_r_[PADR_(cloudabi_clockid_t)];
	char precision_l_[PADL_(cloudabi_timestamp_t)]; cloudabi_timestamp_t precision; char precision_r_[PADR_(cloudabi_timestamp_t)];
};
struct cloudabi_sys_condvar_signal_args {
	char condvar_l_[PADL_(cloudabi_condvar_t *)]; cloudabi_condvar_t * condvar; char condvar_r_[PADR_(cloudabi_condvar_t *)];
	char scope_l_[PADL_(cloudabi_scope_t)]; cloudabi_scope_t scope; char scope_r_[PADR_(cloudabi_scope_t)];
	char nwaiters_l_[PADL_(cloudabi_nthreads_t)]; cloudabi_nthreads_t nwaiters; char nwaiters_r_[PADR_(cloudabi_nthreads_t)];
};
struct cloudabi_sys_fd_close_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
};
struct cloudabi_sys_fd_create1_args {
	char type_l_[PADL_(cloudabi_filetype_t)]; cloudabi_filetype_t type; char type_r_[PADR_(cloudabi_filetype_t)];
};
struct cloudabi_sys_fd_create2_args {
	char type_l_[PADL_(cloudabi_filetype_t)]; cloudabi_filetype_t type; char type_r_[PADR_(cloudabi_filetype_t)];
};
struct cloudabi_sys_fd_datasync_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
};
struct cloudabi_sys_fd_dup_args {
	char from_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t from; char from_r_[PADR_(cloudabi_fd_t)];
};
struct cloudabi64_sys_fd_pread_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char iovs_l_[PADL_(const cloudabi64_iovec_t *)]; const cloudabi64_iovec_t * iovs; char iovs_r_[PADR_(const cloudabi64_iovec_t *)];
	char iovs_len_l_[PADL_(size_t)]; size_t iovs_len; char iovs_len_r_[PADR_(size_t)];
	char offset_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t offset; char offset_r_[PADR_(cloudabi_filesize_t)];
};
struct cloudabi64_sys_fd_pwrite_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char iovs_l_[PADL_(const cloudabi64_ciovec_t *)]; const cloudabi64_ciovec_t * iovs; char iovs_r_[PADR_(const cloudabi64_ciovec_t *)];
	char iovs_len_l_[PADL_(size_t)]; size_t iovs_len; char iovs_len_r_[PADR_(size_t)];
	char offset_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t offset; char offset_r_[PADR_(cloudabi_filesize_t)];
};
struct cloudabi64_sys_fd_read_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char iovs_l_[PADL_(const cloudabi64_iovec_t *)]; const cloudabi64_iovec_t * iovs; char iovs_r_[PADR_(const cloudabi64_iovec_t *)];
	char iovs_len_l_[PADL_(size_t)]; size_t iovs_len; char iovs_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_fd_replace_args {
	char from_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t from; char from_r_[PADR_(cloudabi_fd_t)];
	char to_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t to; char to_r_[PADR_(cloudabi_fd_t)];
};
struct cloudabi_sys_fd_seek_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char offset_l_[PADL_(cloudabi_filedelta_t)]; cloudabi_filedelta_t offset; char offset_r_[PADR_(cloudabi_filedelta_t)];
	char whence_l_[PADL_(cloudabi_whence_t)]; cloudabi_whence_t whence; char whence_r_[PADR_(cloudabi_whence_t)];
};
struct cloudabi_sys_fd_stat_get_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char buf_l_[PADL_(cloudabi_fdstat_t *)]; cloudabi_fdstat_t * buf; char buf_r_[PADR_(cloudabi_fdstat_t *)];
};
struct cloudabi_sys_fd_stat_put_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char buf_l_[PADL_(const cloudabi_fdstat_t *)]; const cloudabi_fdstat_t * buf; char buf_r_[PADR_(const cloudabi_fdstat_t *)];
	char flags_l_[PADL_(cloudabi_fdsflags_t)]; cloudabi_fdsflags_t flags; char flags_r_[PADR_(cloudabi_fdsflags_t)];
};
struct cloudabi_sys_fd_sync_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
};
struct cloudabi64_sys_fd_write_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char iovs_l_[PADL_(const cloudabi64_ciovec_t *)]; const cloudabi64_ciovec_t * iovs; char iovs_r_[PADR_(const cloudabi64_ciovec_t *)];
	char iovs_len_l_[PADL_(size_t)]; size_t iovs_len; char iovs_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_file_advise_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char offset_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t offset; char offset_r_[PADR_(cloudabi_filesize_t)];
	char len_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t len; char len_r_[PADR_(cloudabi_filesize_t)];
	char advice_l_[PADL_(cloudabi_advice_t)]; cloudabi_advice_t advice; char advice_r_[PADR_(cloudabi_advice_t)];
};
struct cloudabi_sys_file_allocate_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char offset_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t offset; char offset_r_[PADR_(cloudabi_filesize_t)];
	char len_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t len; char len_r_[PADR_(cloudabi_filesize_t)];
};
struct cloudabi_sys_file_create_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char type_l_[PADL_(cloudabi_filetype_t)]; cloudabi_filetype_t type; char type_r_[PADR_(cloudabi_filetype_t)];
};
struct cloudabi_sys_file_link_args {
	char fd1_l_[PADL_(cloudabi_lookup_t)]; cloudabi_lookup_t fd1; char fd1_r_[PADR_(cloudabi_lookup_t)];
	char path1_l_[PADL_(const char *)]; const char * path1; char path1_r_[PADR_(const char *)];
	char path1_len_l_[PADL_(size_t)]; size_t path1_len; char path1_len_r_[PADR_(size_t)];
	char fd2_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd2; char fd2_r_[PADR_(cloudabi_fd_t)];
	char path2_l_[PADL_(const char *)]; const char * path2; char path2_r_[PADR_(const char *)];
	char path2_len_l_[PADL_(size_t)]; size_t path2_len; char path2_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_file_open_args {
	char dirfd_l_[PADL_(cloudabi_lookup_t)]; cloudabi_lookup_t dirfd; char dirfd_r_[PADR_(cloudabi_lookup_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char oflags_l_[PADL_(cloudabi_oflags_t)]; cloudabi_oflags_t oflags; char oflags_r_[PADR_(cloudabi_oflags_t)];
	char fds_l_[PADL_(const cloudabi_fdstat_t *)]; const cloudabi_fdstat_t * fds; char fds_r_[PADR_(const cloudabi_fdstat_t *)];
};
struct cloudabi_sys_file_readdir_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char buf_l_[PADL_(void *)]; void * buf; char buf_r_[PADR_(void *)];
	char buf_len_l_[PADL_(size_t)]; size_t buf_len; char buf_len_r_[PADR_(size_t)];
	char cookie_l_[PADL_(cloudabi_dircookie_t)]; cloudabi_dircookie_t cookie; char cookie_r_[PADR_(cloudabi_dircookie_t)];
};
struct cloudabi_sys_file_readlink_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char buf_len_l_[PADL_(size_t)]; size_t buf_len; char buf_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_file_rename_args {
	char fd1_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd1; char fd1_r_[PADR_(cloudabi_fd_t)];
	char path1_l_[PADL_(const char *)]; const char * path1; char path1_r_[PADR_(const char *)];
	char path1_len_l_[PADL_(size_t)]; size_t path1_len; char path1_len_r_[PADR_(size_t)];
	char fd2_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd2; char fd2_r_[PADR_(cloudabi_fd_t)];
	char path2_l_[PADL_(const char *)]; const char * path2; char path2_r_[PADR_(const char *)];
	char path2_len_l_[PADL_(size_t)]; size_t path2_len; char path2_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_file_stat_fget_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char buf_l_[PADL_(cloudabi_filestat_t *)]; cloudabi_filestat_t * buf; char buf_r_[PADR_(cloudabi_filestat_t *)];
};
struct cloudabi_sys_file_stat_fput_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char buf_l_[PADL_(const cloudabi_filestat_t *)]; const cloudabi_filestat_t * buf; char buf_r_[PADR_(const cloudabi_filestat_t *)];
	char flags_l_[PADL_(cloudabi_fsflags_t)]; cloudabi_fsflags_t flags; char flags_r_[PADR_(cloudabi_fsflags_t)];
};
struct cloudabi_sys_file_stat_get_args {
	char fd_l_[PADL_(cloudabi_lookup_t)]; cloudabi_lookup_t fd; char fd_r_[PADR_(cloudabi_lookup_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char buf_l_[PADL_(cloudabi_filestat_t *)]; cloudabi_filestat_t * buf; char buf_r_[PADR_(cloudabi_filestat_t *)];
};
struct cloudabi_sys_file_stat_put_args {
	char fd_l_[PADL_(cloudabi_lookup_t)]; cloudabi_lookup_t fd; char fd_r_[PADR_(cloudabi_lookup_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char buf_l_[PADL_(const cloudabi_filestat_t *)]; const cloudabi_filestat_t * buf; char buf_r_[PADR_(const cloudabi_filestat_t *)];
	char flags_l_[PADL_(cloudabi_fsflags_t)]; cloudabi_fsflags_t flags; char flags_r_[PADR_(cloudabi_fsflags_t)];
};
struct cloudabi_sys_file_symlink_args {
	char path1_l_[PADL_(const char *)]; const char * path1; char path1_r_[PADR_(const char *)];
	char path1_len_l_[PADL_(size_t)]; size_t path1_len; char path1_len_r_[PADR_(size_t)];
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char path2_l_[PADL_(const char *)]; const char * path2; char path2_r_[PADR_(const char *)];
	char path2_len_l_[PADL_(size_t)]; size_t path2_len; char path2_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_file_unlink_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char path_len_l_[PADL_(size_t)]; size_t path_len; char path_len_r_[PADR_(size_t)];
	char flags_l_[PADL_(cloudabi_ulflags_t)]; cloudabi_ulflags_t flags; char flags_r_[PADR_(cloudabi_ulflags_t)];
};
struct cloudabi_sys_lock_unlock_args {
	char lock_l_[PADL_(cloudabi_lock_t *)]; cloudabi_lock_t * lock; char lock_r_[PADR_(cloudabi_lock_t *)];
	char scope_l_[PADL_(cloudabi_scope_t)]; cloudabi_scope_t scope; char scope_r_[PADR_(cloudabi_scope_t)];
};
struct cloudabi_sys_mem_advise_args {
	char mapping_l_[PADL_(void *)]; void * mapping; char mapping_r_[PADR_(void *)];
	char mapping_len_l_[PADL_(size_t)]; size_t mapping_len; char mapping_len_r_[PADR_(size_t)];
	char advice_l_[PADL_(cloudabi_advice_t)]; cloudabi_advice_t advice; char advice_r_[PADR_(cloudabi_advice_t)];
};
struct cloudabi_sys_mem_map_args {
	char addr_l_[PADL_(void *)]; void * addr; char addr_r_[PADR_(void *)];
	char len_l_[PADL_(size_t)]; size_t len; char len_r_[PADR_(size_t)];
	char prot_l_[PADL_(cloudabi_mprot_t)]; cloudabi_mprot_t prot; char prot_r_[PADR_(cloudabi_mprot_t)];
	char flags_l_[PADL_(cloudabi_mflags_t)]; cloudabi_mflags_t flags; char flags_r_[PADR_(cloudabi_mflags_t)];
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char off_l_[PADL_(cloudabi_filesize_t)]; cloudabi_filesize_t off; char off_r_[PADR_(cloudabi_filesize_t)];
};
struct cloudabi_sys_mem_protect_args {
	char mapping_l_[PADL_(void *)]; void * mapping; char mapping_r_[PADR_(void *)];
	char mapping_len_l_[PADL_(size_t)]; size_t mapping_len; char mapping_len_r_[PADR_(size_t)];
	char prot_l_[PADL_(cloudabi_mprot_t)]; cloudabi_mprot_t prot; char prot_r_[PADR_(cloudabi_mprot_t)];
};
struct cloudabi_sys_mem_sync_args {
	char mapping_l_[PADL_(void *)]; void * mapping; char mapping_r_[PADR_(void *)];
	char mapping_len_l_[PADL_(size_t)]; size_t mapping_len; char mapping_len_r_[PADR_(size_t)];
	char flags_l_[PADL_(cloudabi_msflags_t)]; cloudabi_msflags_t flags; char flags_r_[PADR_(cloudabi_msflags_t)];
};
struct cloudabi_sys_mem_unmap_args {
	char mapping_l_[PADL_(void *)]; void * mapping; char mapping_r_[PADR_(void *)];
	char mapping_len_l_[PADL_(size_t)]; size_t mapping_len; char mapping_len_r_[PADR_(size_t)];
};
struct cloudabi64_sys_poll_args {
	char in_l_[PADL_(const cloudabi64_subscription_t *)]; const cloudabi64_subscription_t * in; char in_r_[PADR_(const cloudabi64_subscription_t *)];
	char out_l_[PADL_(cloudabi_event_t *)]; cloudabi_event_t * out; char out_r_[PADR_(cloudabi_event_t *)];
	char nsubscriptions_l_[PADL_(size_t)]; size_t nsubscriptions; char nsubscriptions_r_[PADR_(size_t)];
};
struct cloudabi_sys_proc_exec_args {
	char fd_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t fd; char fd_r_[PADR_(cloudabi_fd_t)];
	char data_l_[PADL_(const void *)]; const void * data; char data_r_[PADR_(const void *)];
	char data_len_l_[PADL_(size_t)]; size_t data_len; char data_len_r_[PADR_(size_t)];
	char fds_l_[PADL_(const cloudabi_fd_t *)]; const cloudabi_fd_t * fds; char fds_r_[PADR_(const cloudabi_fd_t *)];
	char fds_len_l_[PADL_(size_t)]; size_t fds_len; char fds_len_r_[PADR_(size_t)];
};
struct cloudabi_sys_proc_exit_args {
	char rval_l_[PADL_(cloudabi_exitcode_t)]; cloudabi_exitcode_t rval; char rval_r_[PADR_(cloudabi_exitcode_t)];
};
struct cloudabi_sys_proc_fork_args {
	register_t dummy;
};
struct cloudabi_sys_proc_raise_args {
	char sig_l_[PADL_(cloudabi_signal_t)]; cloudabi_signal_t sig; char sig_r_[PADR_(cloudabi_signal_t)];
};
struct cloudabi_sys_random_get_args {
	char buf_l_[PADL_(void *)]; void * buf; char buf_r_[PADR_(void *)];
	char buf_len_l_[PADL_(size_t)]; size_t buf_len; char buf_len_r_[PADR_(size_t)];
};
struct cloudabi64_sys_sock_recv_args {
	char sock_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t sock; char sock_r_[PADR_(cloudabi_fd_t)];
	char in_l_[PADL_(const cloudabi64_recv_in_t *)]; const cloudabi64_recv_in_t * in; char in_r_[PADR_(const cloudabi64_recv_in_t *)];
	char out_l_[PADL_(cloudabi64_recv_out_t *)]; cloudabi64_recv_out_t * out; char out_r_[PADR_(cloudabi64_recv_out_t *)];
};
struct cloudabi64_sys_sock_send_args {
	char sock_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t sock; char sock_r_[PADR_(cloudabi_fd_t)];
	char in_l_[PADL_(const cloudabi64_send_in_t *)]; const cloudabi64_send_in_t * in; char in_r_[PADR_(const cloudabi64_send_in_t *)];
	char out_l_[PADL_(cloudabi64_send_out_t *)]; cloudabi64_send_out_t * out; char out_r_[PADR_(cloudabi64_send_out_t *)];
};
struct cloudabi_sys_sock_shutdown_args {
	char sock_l_[PADL_(cloudabi_fd_t)]; cloudabi_fd_t sock; char sock_r_[PADR_(cloudabi_fd_t)];
	char how_l_[PADL_(cloudabi_sdflags_t)]; cloudabi_sdflags_t how; char how_r_[PADR_(cloudabi_sdflags_t)];
};
struct cloudabi64_sys_thread_create_args {
	char attr_l_[PADL_(cloudabi64_threadattr_t *)]; cloudabi64_threadattr_t * attr; char attr_r_[PADR_(cloudabi64_threadattr_t *)];
};
struct cloudabi_sys_thread_exit_args {
	char lock_l_[PADL_(cloudabi_lock_t *)]; cloudabi_lock_t * lock; char lock_r_[PADR_(cloudabi_lock_t *)];
	char scope_l_[PADL_(cloudabi_scope_t)]; cloudabi_scope_t scope; char scope_r_[PADR_(cloudabi_scope_t)];
};
struct cloudabi_sys_thread_yield_args {
	register_t dummy;
};
int	cloudabi_sys_clock_res_get(struct thread *, struct cloudabi_sys_clock_res_get_args *);
int	cloudabi_sys_clock_time_get(struct thread *, struct cloudabi_sys_clock_time_get_args *);
int	cloudabi_sys_condvar_signal(struct thread *, struct cloudabi_sys_condvar_signal_args *);
int	cloudabi_sys_fd_close(struct thread *, struct cloudabi_sys_fd_close_args *);
int	cloudabi_sys_fd_create1(struct thread *, struct cloudabi_sys_fd_create1_args *);
int	cloudabi_sys_fd_create2(struct thread *, struct cloudabi_sys_fd_create2_args *);
int	cloudabi_sys_fd_datasync(struct thread *, struct cloudabi_sys_fd_datasync_args *);
int	cloudabi_sys_fd_dup(struct thread *, struct cloudabi_sys_fd_dup_args *);
int	cloudabi64_sys_fd_pread(struct thread *, struct cloudabi64_sys_fd_pread_args *);
int	cloudabi64_sys_fd_pwrite(struct thread *, struct cloudabi64_sys_fd_pwrite_args *);
int	cloudabi64_sys_fd_read(struct thread *, struct cloudabi64_sys_fd_read_args *);
int	cloudabi_sys_fd_replace(struct thread *, struct cloudabi_sys_fd_replace_args *);
int	cloudabi_sys_fd_seek(struct thread *, struct cloudabi_sys_fd_seek_args *);
int	cloudabi_sys_fd_stat_get(struct thread *, struct cloudabi_sys_fd_stat_get_args *);
int	cloudabi_sys_fd_stat_put(struct thread *, struct cloudabi_sys_fd_stat_put_args *);
int	cloudabi_sys_fd_sync(struct thread *, struct cloudabi_sys_fd_sync_args *);
int	cloudabi64_sys_fd_write(struct thread *, struct cloudabi64_sys_fd_write_args *);
int	cloudabi_sys_file_advise(struct thread *, struct cloudabi_sys_file_advise_args *);
int	cloudabi_sys_file_allocate(struct thread *, struct cloudabi_sys_file_allocate_args *);
int	cloudabi_sys_file_create(struct thread *, struct cloudabi_sys_file_create_args *);
int	cloudabi_sys_file_link(struct thread *, struct cloudabi_sys_file_link_args *);
int	cloudabi_sys_file_open(struct thread *, struct cloudabi_sys_file_open_args *);
int	cloudabi_sys_file_readdir(struct thread *, struct cloudabi_sys_file_readdir_args *);
int	cloudabi_sys_file_readlink(struct thread *, struct cloudabi_sys_file_readlink_args *);
int	cloudabi_sys_file_rename(struct thread *, struct cloudabi_sys_file_rename_args *);
int	cloudabi_sys_file_stat_fget(struct thread *, struct cloudabi_sys_file_stat_fget_args *);
int	cloudabi_sys_file_stat_fput(struct thread *, struct cloudabi_sys_file_stat_fput_args *);
int	cloudabi_sys_file_stat_get(struct thread *, struct cloudabi_sys_file_stat_get_args *);
int	cloudabi_sys_file_stat_put(struct thread *, struct cloudabi_sys_file_stat_put_args *);
int	cloudabi_sys_file_symlink(struct thread *, struct cloudabi_sys_file_symlink_args *);
int	cloudabi_sys_file_unlink(struct thread *, struct cloudabi_sys_file_unlink_args *);
int	cloudabi_sys_lock_unlock(struct thread *, struct cloudabi_sys_lock_unlock_args *);
int	cloudabi_sys_mem_advise(struct thread *, struct cloudabi_sys_mem_advise_args *);
int	cloudabi_sys_mem_map(struct thread *, struct cloudabi_sys_mem_map_args *);
int	cloudabi_sys_mem_protect(struct thread *, struct cloudabi_sys_mem_protect_args *);
int	cloudabi_sys_mem_sync(struct thread *, struct cloudabi_sys_mem_sync_args *);
int	cloudabi_sys_mem_unmap(struct thread *, struct cloudabi_sys_mem_unmap_args *);
int	cloudabi64_sys_poll(struct thread *, struct cloudabi64_sys_poll_args *);
int	cloudabi_sys_proc_exec(struct thread *, struct cloudabi_sys_proc_exec_args *);
int	cloudabi_sys_proc_exit(struct thread *, struct cloudabi_sys_proc_exit_args *);
int	cloudabi_sys_proc_fork(struct thread *, struct cloudabi_sys_proc_fork_args *);
int	cloudabi_sys_proc_raise(struct thread *, struct cloudabi_sys_proc_raise_args *);
int	cloudabi_sys_random_get(struct thread *, struct cloudabi_sys_random_get_args *);
int	cloudabi64_sys_sock_recv(struct thread *, struct cloudabi64_sys_sock_recv_args *);
int	cloudabi64_sys_sock_send(struct thread *, struct cloudabi64_sys_sock_send_args *);
int	cloudabi_sys_sock_shutdown(struct thread *, struct cloudabi_sys_sock_shutdown_args *);
int	cloudabi64_sys_thread_create(struct thread *, struct cloudabi64_sys_thread_create_args *);
int	cloudabi_sys_thread_exit(struct thread *, struct cloudabi_sys_thread_exit_args *);
int	cloudabi_sys_thread_yield(struct thread *, struct cloudabi_sys_thread_yield_args *);

#ifdef COMPAT_43


#endif /* COMPAT_43 */


#ifdef COMPAT_FREEBSD4


#endif /* COMPAT_FREEBSD4 */


#ifdef COMPAT_FREEBSD6


#endif /* COMPAT_FREEBSD6 */


#ifdef COMPAT_FREEBSD7


#endif /* COMPAT_FREEBSD7 */


#ifdef COMPAT_FREEBSD10


#endif /* COMPAT_FREEBSD10 */


#ifdef COMPAT_FREEBSD11


#endif /* COMPAT_FREEBSD11 */


#ifdef COMPAT_FREEBSD12


#endif /* COMPAT_FREEBSD12 */

#define	CLOUDABI64_SYS_AUE_cloudabi_sys_clock_res_get	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_clock_time_get	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_condvar_signal	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_close	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_create1	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_create2	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_datasync	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_dup	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_fd_pread	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_fd_pwrite	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_fd_read	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_replace	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_seek	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_stat_get	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_stat_put	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_fd_sync	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_fd_write	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_advise	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_allocate	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_create	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_link	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_open	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_readdir	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_readlink	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_rename	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_stat_fget	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_stat_fput	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_stat_get	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_stat_put	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_symlink	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_file_unlink	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_lock_unlock	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_mem_advise	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_mem_map	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_mem_protect	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_mem_sync	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_mem_unmap	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_poll	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_proc_exec	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_proc_exit	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_proc_fork	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_proc_raise	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_random_get	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_sock_recv	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_sock_send	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_sock_shutdown	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi64_sys_thread_create	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_thread_exit	AUE_NULL
#define	CLOUDABI64_SYS_AUE_cloudabi_sys_thread_yield	AUE_NULL

#undef PAD_
#undef PADL_
#undef PADR_

#endif /* !_CLOUDABI64_SYSPROTO_H_ */
