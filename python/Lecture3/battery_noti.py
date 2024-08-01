from plyer import notification
import psutil

# الحصول على حالة البطارية
battery_status = psutil.sensors_battery()

# طباعة حالة البطارية في الوحدة الطرفية
print(f"Battery Percentage: {battery_status.percent}%")

# إعداد نص الإشعار بناءً على حالة البطارية
if battery_status.power_plugged:
    title = "Battery Status: Charging"
    message = f"Battery is charging. Current level: {battery_status.percent}%"
else:
    title = "Battery Status: Discharging"
    message = f"Battery level: {battery_status.percent}%\nTime left: {battery_status.secsleft // 60} minutes" if battery_status.secsleft != psutil.POWER_TIME_UNLIMITED else "Time left: Calculating..."

# إظهار الإشعار باستخدام plyer
notification.notify(
    title=title,
    message=message,
    timeout=10,  # مدة الإشعار بالثواني
    app_name='Battery Monitor'  # اسم التطبيق الذي يظهر الإشعار
)
