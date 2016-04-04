%global tests_enabled 0

Name:           procps-ng
Version:        3.3.9
Release:        1
License:        GPL-2.0 and LGPL-2.0+
Summary:        System and process monitoring utilities
Url:            https://sourceforge.net/projects/procps-ng/
Group:          Base/Utilities
Source:         http://downloads.sourceforge.net/%{name}/%{name}-%{version}.tar.xz
Source1001: 	procps-ng.manifest

Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig

BuildRequires:  autoconf
BuildRequires:  automake
BuildRequires:  gettext-devel
BuildRequires:  libtool
BuildRequires:  ncurses-devel

%if %{tests_enabled}
BuildRequires:  dejagnu
%endif

Provides:       procps = %{version}
Obsoletes:      procps < 3.3.4-1

Provides:       /sbin/sysctl
Provides:       /bin/ps

%description
The procps package contains a set of system utilities that provide
system information. Procps includes ps, free, skill, pkill, pgrep,
snice, tload, top, uptime, vmstat, w, watch and pwdx. The ps command
displays a snapshot of running processes. The top command provides
a repetitive update of the statuses of running processes. The free
command displays the amounts of free and used memory on your
system. The skill command sends a terminate command (or another
specified signal) to a specified set of processes. The snice
command is used to change the scheduling priority of specified
processes. The tload command prints a graph of the current system
load average to a specified tty. The uptime command displays the
current time, how long the system has been running, how many users
are logged on, and system load averages for the past one, five,
and fifteen minutes. The w command displays a list of the users
who are currently logged on and what they are running. The watch
program watches a running program. The vmstat command displays
virtual memory statistics about processes, memory, paging, block
I/O, traps, and CPU activity. The pwdx command reports the current
working directory of a process or processes.

%package devel
Summary:        System and process monitoring utilities
Group:          Development/Libraries
Requires:       %{name}%{?_isa} = %{version}
Provides:       procps-devel = %{version}
Obsoletes:      procps-devel < 3.3.4-1

%description devel
System and process monitoring utilities development headers

%prep
%setup -q
cp %{SOURCE1001} .

%build
export CFLAGS+=" -fvisibility=hidden"
  export CXXFLAGS+=" -fvisibility=hidden"
  
%reconfigure --prefix=/ \
             --exec-prefix=/ \
             --docdir=/unwanted \
             --disable-static \
             --disable-w-from \
             --disable-kill \
             --disable-rpath

make CFLAGS="%{optflags} -fvisibility=hidden"

%if %{tests_enabled}
%check
make check
%endif


%install
%make_install

mkdir -p %{buildroot}%{_sysconfdir}/sysctl.d
rm -rf %{buildroot}/unwanted

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%docs_package

%files
%manifest %{name}.manifest
%license COPYING COPYING.LIB
%{_libdir}/libprocps.so.*
%{_bindir}/*
%{_sbindir}/*
%{_sysconfdir}/sysctl.d

%exclude %{_sysconfdir}/sysctl.conf

%files devel
%manifest %{name}.manifest
%{_libdir}/libprocps.so
%{_includedir}/proc
%{_libdir}/pkgconfig/libprocps.pc

%changelog
