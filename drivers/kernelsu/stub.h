#pragma once

// stub for old kernelsu hooks, for users on manual hooks
// https://kernelsu.org/guide/how-to-integrate-for-non-gki.html

#if !defined(CONFIG_KSU_TAMPER_SYSCALL_TABLE) && !defined(CONFIG_KSU_HACK_ARM64_BRANCH_LINK)

/* not used anymore so just set it to false */
bool ksu_execveat_hook __read_mostly = false;

/* now just an alias to ksu_handle_execveat */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 14, 0)
int ksu_handle_execveat_sucompat(int *fd, struct filename **filename_ptr, void *argv, void *envp, int *flags) __attribute__((alias("ksu_handle_execveat")));
#endif

// no-op
int ksu_handle_vfs_read(struct file **file_ptr, char __user **buf_ptr, size_t *count_ptr, loff_t **pos) { return 0; }

// no-op
int ksu_handle_input_handle_event(unsigned int *type, unsigned int *code, int *value) { return 0; }

// no-op
int ksu_handle_devpts(struct inode*) { return 0; }

#endif
