cmd_/home/tony/Desktop/Linux_Programing/kernel_module/cpufreq_new/modules.order := {   echo /home/tony/Desktop/Linux_Programing/kernel_module/cpufreq_new/cpufreq.ko; :; } | awk '!x[$$0]++' - > /home/tony/Desktop/Linux_Programing/kernel_module/cpufreq_new/modules.order