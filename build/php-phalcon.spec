%global builddir build/%{__isa_bits}bits
%global	php_apiver  %((echo 0; php -i 2>/dev/null | sed -n 's/^PHP API => //p') | tail -1)
%{!?php_extdir:	%{expand:	%%global php_extdir	%(php-config --extension-dir)}}

Name:           php-phalcon
Version:        2.0.2
Release:        0%{?dist}
Summary:        A full-stack PHP framework delivered as a C-extension
License:        New BSD, Zend, PHP
URL:            http://phalconphp.com/
Source0:        https://github.com/phalcon/cphalcon/archive/phalcon-v%{version}.tar.gz

BuildRequires:  php-devel libtool pcre-devel >= 5.3 gcc make
%if 0%{?php_zend_api:1}
Requires:		php(zend-abi) = %{php_zend_api}
Requires:		php(api) = %{php_core_api}
%else
Requires:		php-api = %{php_apiver}
%endif

%description
Phalcon is an open source, full stack framework for PHP written as a C-extension, optimized for high performance.
You don't need to learn or use the C language, since the functionality is exposed as PHP classes ready for you to use.
Phalcon also is loosely coupled, allowing you to use its objects as glue components based on the needs of your application.

%prep
%setup -qn cphalcon-phalcon-v%{version}

%build
CPPFLAGS="-DPHALCON_RELEASE"
CFLAGS="%{optflags} -O2 -finline-functions -fomit-frame-pointer -fvisibility=hidden"
pushd %{builddir}
phpize
%configure --enable-phalcon
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%{__mkdir_p} %{buildroot}%{php_extdir}
%{__mkdir_p} %{buildroot}%{_sysconfdir}/php.d/
pushd %{builddir}
make install INSTALL_ROOT=%{buildroot}
echo "extension=phalcon.so" >> %{buildroot}%{_sysconfdir}/php.d/phalcon.ini

%files
%{php_extdir}/phalcon.so
%{_sysconfdir}/php.d/phalcon.ini

%clean
rm -rf %{buildroot}

%changelog
* Tue Jun 02 2015 George Machitidze <giomac@gmail.com> - 2.0.2
- Initial build
