# OpenGL_Fundamentals
Modern OpenGL kullanarak ekrana kırmızı üçgen yazdırma.

#Projenin Çalışması İçin Gereken Kütüphaneler

<ul>  
  <li>GLFW 3.3.2
   <ul>
    <li> İndirme Linki: https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.zip </li>
    <li> Include dosyalarını ekleme

    Include dosyasını bu adresten kopyalayın (…\dependencies\glfw-3.3.2.bin.WIN32\include)
    Visual Studio'da açtığınız projeye gidin
    Project Properties -> Configuration Properties -> C/C++ -> General -> Additional Include Directories
    Adresi buraya yapıştırın, doğruluğundan emin olun. Uygula ve Tamam butonuna basın.

Lib Dosyalarını ekleme

Bu adım için, kullandığınız Visual Studio sürümüne bağlı olan binary'i koyalamanız gerekli. Örnek olarak, eğer Visual Studio 2012 kullanıyorsanız, VS2012 binary adresini kopyalamanız gerekiyor (GLFW 3.3.2 için lib-vc2019 dosyası).

    Doğru adresi kopyaladığınızdan emin olun (VS 2019 ve GLFW-32 bit kullanıyorum) it is …\dependencies\glfw-3.3.2.bin.WIN32\lib-vc2019)
    Visual Studio'da açtığınız projeye gidin
    Project Properties -> Configuration Properties -> Linker -> General -> Additional Library Directories
    Adresi yapıştırıp Uygula ve Tamam butonuna basın
    Son olarak Properties -> Configuration Properties -> Linker -> Input -> Additional Dependencies kısmına her birinin arasında";" işareti olacak şekilde şunları ekleyin: glfw3.lib and glfw3dll.lib (örnek olarak "glfw3.lib;glfw3dll.lib" gibi)
    Uygula ve tamama tıklayın, ekleme işlemi tamamlanmıştır.
</li>
   </ul>
  </li>
  <li>GLEW 2.1.0
    <ul>
      <li>İndirme Linki: https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0-win32.zip/download </li>
      <li> Include dosyalarını ekleme

    Include dosyasını bu adresten kopyalayın  …\dependencies\glew-2.1.0\include\GL
    Visual Studio'da açtığınız projeye gidin
    Project Properties -> Configuration Properties -> C/C++ -> General -> Additional Include Directories
    Adresi yapıştırıp Uygula ve Tamam butonuna basın

Lib Dosyalarını ekleme

    .lib dosyalarının adresini kopyalayın (Adres buna benzer bir şey olmalı …\dependencies\glew-2.1.0\lib\Release\x64). Eğer projeniz 32-bit ise, 32-bit adresi kopyalanmalı (bunun gibi …\dependencies\glew-2.1.0\lib\Release\Win32)
    Visual Studio'da açtığınız projeye gidin
    Project Properties -> Configuration Properties -> Linker -> General -> Additional Library Directories
    Adresi yapıştırıp Uygula ve Tamam butonuna basın
    Son olarak, Project Properties -> Configuration Properties -> Linker -> Input -> Additional Dependencies kısmına her birinin arasında ";" işareti olacak şekilde şunları ekleyin: opengl32.lib glu32.lib glew32.lib (örnek olarak "opengl132.lib;glu32.lib;glew32.lib" gibi)
    Uygula ve tamama tıklayın, ekleme işlemi tamamlanmıştır.
</li>
    </ul>  
  </ul>


#Kaynak Kodun Çıktısı

![](https://github.com/cagin2245/OpenGL_Fundamentals/blob/master/output.PNG)


#Proje Visual Studio 2019 Kullanılarak derlenmiştir
