/* simple kernel moudule hello_world */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/cpufreq.h>

static void cpufreq_gov_performance_limits(struct cpufreq_policy *policy)
{
    pr_debug("setting to %u kHz\n", policy->max);
    __cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
}

static struct cpufreq_governor cpufreq_gov_new = {
    .name   = "new",
    .owner  = THIS_MODULE,
    .limits = cpufreq_gov_performance_limits,
};

cpufreq_governor_init(cpufreq_gov_new); //using insmod, it will enter hello_init
cpufreq_governor_exit(cpufreq_gov_new); //using rmmod, it will enter hello_exit

MODULE_LICENSE("GPL");

