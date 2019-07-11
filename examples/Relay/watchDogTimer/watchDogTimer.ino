// Данный пример демонстрирует программную перезагрузку модуля.     // * Строки со звёздочкой являются необязательными.
                                                                    //
#include <Wire.h>                                                   // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Relay.h>                                     //   Подключаем библиотеку для работы с реле и силовыми ключами.
iarduino_I2C_Relay relay(0x09);                                     //   Объявляем объект relay для работы с функциями и методами библиотеки iarduino_I2C_Relay, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Relay relay;), то адрес будет найден автоматически.
void setup(){                                                       //
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
//  Готовим модуль к работе:                                        //
    relay.begin();                                                  //   Инициируем работу с модулем.
}                                                                   //
                                                                    //
void loop(){                                                        //
//  Включаем все каналы модуля:                                     //
    relay.digitalWrite(ALL_CHANNEL,HIGH);                           // * Включаем все каналы модуля.
    delay(2000);                                                    //   Ждём две секунды.
//  Перезагружаем модуль:                                           //
    relay.reset();                                                  //   После перезагрузки все регистры сбросятся в значения по умолчанию, все каналы будут отключены.
    delay(2000);                                                    //   Ждём две секунды.
}                                                                   //