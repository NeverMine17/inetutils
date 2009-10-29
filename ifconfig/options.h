/*
  Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009
  Free Software Foundation, Inc.

  This file is part of GNU Inetutils.

  GNU Inetutils is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  GNU Inetutils is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see `http://www.gnu.org/licenses/'. */

/* Written by Marcus Brinkmann.  */

#ifndef IFCONFIG_OPTIONS_H
# define IFCONFIG_OPTIONS_H

# include <sys/types.h>
# include <sys/socket.h>

struct ifconfig *parse_opt_new_ifs (char *name);

/* One per interface mentioned on the command line.  */
struct ifconfig
{
  char *name;
  int valid;
# define IF_VALID_SYSTEM		0x001
  struct system_ifconfig *system;
# define IF_VALID_FORMAT		0x002
  const char *format;
# define IF_VALID_AF		0x004
  sa_family_t af;
# define IF_VALID_ADDR		0x008
  char *address;
# define IF_VALID_NETMASK	0x010
  char *netmask;
# define IF_VALID_DSTADDR	0x020
  char *dstaddr;
# define IF_VALID_BRDADDR	0x040
  char *brdaddr;
# define IF_VALID_MTU		0x080
  int mtu;
# define IF_VALID_METRIC		0x100
  int metric;
};

struct format
{
  const char *name;
  const char *templ;
};

extern struct format formats[];

/* Array of interfaces mentioned on the command line.  */
extern struct ifconfig *ifs;
extern int nifs;

/* Be verbose about what we do.  */
extern int verbose;

void usage (int err);
void parse_opt_set_address (struct ifconfig *ifp, char *addr);
void parse_opt_set_brdaddr (struct ifconfig *ifp, char *addr);
void parse_opt_set_dstaddr (struct ifconfig *ifp, char *addr);
void parse_opt_set_netmask (struct ifconfig *ifp, char *addr);
void parse_opt_set_mtu (struct ifconfig *ifp, char *addr);
void parse_opt_set_metric (struct ifconfig *ifp, char *addr);
void parse_opt_set_default_format (const char *format);
void parse_opt_finalize (struct ifconfig *ifp);

void parse_cmdline (int argc, char *argv[]);

#endif
