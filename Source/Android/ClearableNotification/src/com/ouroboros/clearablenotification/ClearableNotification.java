package com.ouroboros.clearablenotification;

import android.app.Notification;
import de.robv.android.xposed.IXposedHookLoadPackage;
import de.robv.android.xposed.XposedHelpers;
import de.robv.android.xposed.XC_MethodHook;
import de.robv.android.xposed.callbacks.XC_LoadPackage.LoadPackageParam;

public class ClearableNotification implements IXposedHookLoadPackage {

    @Override
    public void handleLoadPackage(LoadPackageParam pkg) throws Throwable {
        if (pkg.packageName.equals("com.tencent.mobileqq") == false)
            return;

        XposedHelpers.findAndHookMethod("android.app.NotificationManager", pkg.classLoader, "notify", int.class, Notification.class,new XC_MethodHook() {
            @Override
            protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                modifyFlag(param.args[1]);
                super.beforeHookedMethod(param);
            }
        });

        XposedHelpers.findAndHookMethod("android.app.NotificationManager", pkg.classLoader, "notify", String.class, int.class, Notification.class,new XC_MethodHook() {
            @Override
            protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                modifyFlag(param.args[2]);
                super.beforeHookedMethod(param);
            }
        });
    }

    public void modifyFlag(Object obj){
        Notification notify = (Notification) obj;
        notify.flags &= ~Notification.FLAG_ONGOING_EVENT;
        notify.flags |= Notification.FLAG_AUTO_CANCEL;
    }
}
