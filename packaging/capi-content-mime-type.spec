Name:       capi-content-mime-type
Summary:    A MIME type library in Tizen C API
Version:    0.0.3
Release:    3
Group:      TO_BE/FILLED_IN
License:    TO BE FILLED IN
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(xdgmime)
Requires(post): /sbin/ldconfig  
Requires(postun): /sbin/ldconfig

%description


%package devel
Summary:  A MIME type library in Tizen C API (Development)
Group:    TO_BE/FILLED_IN
Requires: %{name} = %{version}-%{release}
Requires:  pkgconfig(capi-base-common)

%description devel


%prep
%setup -q


%build
%if 0%{?sec_build_binary_debug_enable}
export CFLAGS="$CFLAGS -DTIZEN_DEBUG_ENABLE"
export CXXFLAGS="$CXXFLAGS -DTIZEN_DEBUG_ENABLE"
export FFLAGS="$FFLAGS -DTIZEN_DEBUG_ENABLE"
%endif
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`  
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DFULLVER=%{version} -DMAJORVER=${MAJORVER} 


make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}/usr/share/license
install LICENSE %{buildroot}/usr/share/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%{_libdir}/lib*.so.*
%manifest capi-content-mime-type.manifest
/usr/share/license/%{name}

%files devel
%{_includedir}/content/*.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/lib*.so


