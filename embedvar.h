/* !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!! 
   This file is built by embed.pl from global.sym, intrpvar.h,
   and thrdvar.h.  Any changes made here will be lost!
*/

/* (Doing namespace management portably in C is really gross.) */

/*  EMBED has no run-time penalty, but helps keep the Perl namespace
    from colliding with that used by other libraries pulled in
    by extensions or by embedding perl.  Allow a cc -DNO_EMBED
    override, however, to keep binary compatability with previous
    versions of perl.
*/


/* Put interpreter-specific symbols into a struct? */

#ifdef MULTIPLICITY

#ifndef USE_THREADS
/* If we do not have threads then per-thread vars are per-interpreter */

#define Sv			(curinterp->TSv)
#define Xpv			(curinterp->TXpv)
#define av_fetch_sv		(curinterp->Tav_fetch_sv)
#define bodytarget		(curinterp->Tbodytarget)
#define chopset			(curinterp->Tchopset)
#define curcop			(curinterp->Tcurcop)
#define curpad			(curinterp->Tcurpad)
#define curpm			(curinterp->Tcurpm)
#define curstack		(curinterp->Tcurstack)
#define curstackinfo		(curinterp->Tcurstackinfo)
#define curstash		(curinterp->Tcurstash)
#define defoutgv		(curinterp->Tdefoutgv)
#define defstash		(curinterp->Tdefstash)
#define delaymagic		(curinterp->Tdelaymagic)
#define dirty			(curinterp->Tdirty)
#define formtarget		(curinterp->Tformtarget)
#define hv_fetch_ent_mh		(curinterp->Thv_fetch_ent_mh)
#define hv_fetch_sv		(curinterp->Thv_fetch_sv)
#define in_eval			(curinterp->Tin_eval)
#define last_in_gv		(curinterp->Tlast_in_gv)
#define localizing		(curinterp->Tlocalizing)
#define mainstack		(curinterp->Tmainstack)
#define markstack		(curinterp->Tmarkstack)
#define markstack_max		(curinterp->Tmarkstack_max)
#define markstack_ptr		(curinterp->Tmarkstack_ptr)
#define nrs			(curinterp->Tnrs)
#define ofs			(curinterp->Tofs)
#define ofslen			(curinterp->Tofslen)
#define op			(curinterp->Top)
#define opsave			(curinterp->Topsave)
#define restartop		(curinterp->Trestartop)
#define retstack		(curinterp->Tretstack)
#define retstack_ix		(curinterp->Tretstack_ix)
#define retstack_max		(curinterp->Tretstack_max)
#define rs			(curinterp->Trs)
#define savestack		(curinterp->Tsavestack)
#define savestack_ix		(curinterp->Tsavestack_ix)
#define savestack_max		(curinterp->Tsavestack_max)
#define scopestack		(curinterp->Tscopestack)
#define scopestack_ix		(curinterp->Tscopestack_ix)
#define scopestack_max		(curinterp->Tscopestack_max)
#define stack_base		(curinterp->Tstack_base)
#define stack_max		(curinterp->Tstack_max)
#define stack_sp		(curinterp->Tstack_sp)
#define start_env		(curinterp->Tstart_env)
#define statbuf			(curinterp->Tstatbuf)
#define tainted			(curinterp->Ttainted)
#define timesbuf		(curinterp->Ttimesbuf)
#define tmps_floor		(curinterp->Ttmps_floor)
#define tmps_ix			(curinterp->Ttmps_ix)
#define tmps_max		(curinterp->Ttmps_max)
#define tmps_stack		(curinterp->Ttmps_stack)
#define top_env			(curinterp->Ttop_env)
#define toptarget		(curinterp->Ttoptarget)

#endif /* !USE_THREADS */

/* These are always per-interpreter if there is more than one */

#define Argv			(curinterp->IArgv)
#define Cmd			(curinterp->ICmd)
#define DBgv			(curinterp->IDBgv)
#define DBline			(curinterp->IDBline)
#define DBsignal		(curinterp->IDBsignal)
#define DBsingle		(curinterp->IDBsingle)
#define DBsub			(curinterp->IDBsub)
#define DBtrace			(curinterp->IDBtrace)
#define ampergv			(curinterp->Iampergv)
#define argvgv			(curinterp->Iargvgv)
#define argvoutgv		(curinterp->Iargvoutgv)
#define basetime		(curinterp->Ibasetime)
#define beginav			(curinterp->Ibeginav)
#define cddir			(curinterp->Icddir)
#define copline			(curinterp->Icopline)
#define curcopdb		(curinterp->Icurcopdb)
#define curstname		(curinterp->Icurstname)
#define dbargs			(curinterp->Idbargs)
#define debdelim		(curinterp->Idebdelim)
#define debname			(curinterp->Idebname)
#define debstash		(curinterp->Idebstash)
#define defgv			(curinterp->Idefgv)
#define diehook			(curinterp->Idiehook)
#define dlevel			(curinterp->Idlevel)
#define dlmax			(curinterp->Idlmax)
#define doextract		(curinterp->Idoextract)
#define doswitches		(curinterp->Idoswitches)
#define dowarn			(curinterp->Idowarn)
#define dumplvl			(curinterp->Idumplvl)
#define e_fp			(curinterp->Ie_fp)
#define e_tmpname		(curinterp->Ie_tmpname)
#define endav			(curinterp->Iendav)
#define envgv			(curinterp->Ienvgv)
#define errgv			(curinterp->Ierrgv)
#define eval_root		(curinterp->Ieval_root)
#define eval_start		(curinterp->Ieval_start)
#define fdpid			(curinterp->Ifdpid)
#define filemode		(curinterp->Ifilemode)
#define firstgv			(curinterp->Ifirstgv)
#define forkprocess		(curinterp->Iforkprocess)
#define formfeed		(curinterp->Iformfeed)
#define gensym			(curinterp->Igensym)
#define globalstash		(curinterp->Iglobalstash)
#define incgv			(curinterp->Iincgv)
#define initav			(curinterp->Iinitav)
#define inplace			(curinterp->Iinplace)
#define lastfd			(curinterp->Ilastfd)
#define lastscream		(curinterp->Ilastscream)
#define lastsize		(curinterp->Ilastsize)
#define lastspbase		(curinterp->Ilastspbase)
#define laststatval		(curinterp->Ilaststatval)
#define laststype		(curinterp->Ilaststype)
#define leftgv			(curinterp->Ileftgv)
#define lineary			(curinterp->Ilineary)
#define localpatches		(curinterp->Ilocalpatches)
#define main_cv			(curinterp->Imain_cv)
#define main_root		(curinterp->Imain_root)
#define main_start		(curinterp->Imain_start)
#define maxscream		(curinterp->Imaxscream)
#define maxsysfd		(curinterp->Imaxsysfd)
#define mess_sv			(curinterp->Imess_sv)
#define minus_F			(curinterp->Iminus_F)
#define minus_a			(curinterp->Iminus_a)
#define minus_c			(curinterp->Iminus_c)
#define minus_l			(curinterp->Iminus_l)
#define minus_n			(curinterp->Iminus_n)
#define minus_p			(curinterp->Iminus_p)
#define multiline		(curinterp->Imultiline)
#define mystrk			(curinterp->Imystrk)
#define ofmt			(curinterp->Iofmt)
#define oldlastpm		(curinterp->Ioldlastpm)
#define oldname			(curinterp->Ioldname)
#define op_mask			(curinterp->Iop_mask)
#define origargc		(curinterp->Iorigargc)
#define origargv		(curinterp->Iorigargv)
#define origfilename		(curinterp->Iorigfilename)
#define ors			(curinterp->Iors)
#define orslen			(curinterp->Iorslen)
#define parsehook		(curinterp->Iparsehook)
#define patchlevel		(curinterp->Ipatchlevel)
#define perl_destruct_level	(curinterp->Iperl_destruct_level)
#define perldb			(curinterp->Iperldb)
#define preambleav		(curinterp->Ipreambleav)
#define preambled		(curinterp->Ipreambled)
#define preprocess		(curinterp->Ipreprocess)
#define rightgv			(curinterp->Irightgv)
#define sawampersand		(curinterp->Isawampersand)
#define sawstudy		(curinterp->Isawstudy)
#define sawvec			(curinterp->Isawvec)
#define screamfirst		(curinterp->Iscreamfirst)
#define screamnext		(curinterp->Iscreamnext)
#define secondgv		(curinterp->Isecondgv)
#define siggv			(curinterp->Isiggv)
#define sortcop			(curinterp->Isortcop)
#define sortstash		(curinterp->Isortstash)
#define splitstr		(curinterp->Isplitstr)
#define statcache		(curinterp->Istatcache)
#define statgv			(curinterp->Istatgv)
#define statname		(curinterp->Istatname)
#define statusvalue		(curinterp->Istatusvalue)
#define statusvalue_vms		(curinterp->Istatusvalue_vms)
#define stdingv			(curinterp->Istdingv)
#define strchop			(curinterp->Istrchop)
#define strtab			(curinterp->Istrtab)
#define sv_arenaroot		(curinterp->Isv_arenaroot)
#define sv_count		(curinterp->Isv_count)
#define sv_objcount		(curinterp->Isv_objcount)
#define sv_root			(curinterp->Isv_root)
#define tainting		(curinterp->Itainting)
#define threadnum		(curinterp->Ithreadnum)
#define thrsv			(curinterp->Ithrsv)
#define unsafe			(curinterp->Iunsafe)
#define warnhook		(curinterp->Iwarnhook)

#else	/* !MULTIPLICITY */

#define IArgv			Argv
#define ICmd			Cmd
#define IDBgv			DBgv
#define IDBline			DBline
#define IDBsignal		DBsignal
#define IDBsingle		DBsingle
#define IDBsub			DBsub
#define IDBtrace		DBtrace
#define Iampergv		ampergv
#define Iargvgv			argvgv
#define Iargvoutgv		argvoutgv
#define Ibasetime		basetime
#define Ibeginav		beginav
#define Icddir			cddir
#define Icopline		copline
#define Icurcopdb		curcopdb
#define Icurstname		curstname
#define Idbargs			dbargs
#define Idebdelim		debdelim
#define Idebname		debname
#define Idebstash		debstash
#define Idefgv			defgv
#define Idiehook		diehook
#define Idlevel			dlevel
#define Idlmax			dlmax
#define Idoextract		doextract
#define Idoswitches		doswitches
#define Idowarn			dowarn
#define Idumplvl		dumplvl
#define Ie_fp			e_fp
#define Ie_tmpname		e_tmpname
#define Iendav			endav
#define Ienvgv			envgv
#define Ierrgv			errgv
#define Ieval_root		eval_root
#define Ieval_start		eval_start
#define Ifdpid			fdpid
#define Ifilemode		filemode
#define Ifirstgv		firstgv
#define Iforkprocess		forkprocess
#define Iformfeed		formfeed
#define Igensym			gensym
#define Iglobalstash		globalstash
#define Iincgv			incgv
#define Iinitav			initav
#define Iinplace		inplace
#define Ilastfd			lastfd
#define Ilastscream		lastscream
#define Ilastsize		lastsize
#define Ilastspbase		lastspbase
#define Ilaststatval		laststatval
#define Ilaststype		laststype
#define Ileftgv			leftgv
#define Ilineary		lineary
#define Ilocalpatches		localpatches
#define Imain_cv		main_cv
#define Imain_root		main_root
#define Imain_start		main_start
#define Imaxscream		maxscream
#define Imaxsysfd		maxsysfd
#define Imess_sv		mess_sv
#define Iminus_F		minus_F
#define Iminus_a		minus_a
#define Iminus_c		minus_c
#define Iminus_l		minus_l
#define Iminus_n		minus_n
#define Iminus_p		minus_p
#define Imultiline		multiline
#define Imystrk			mystrk
#define Iofmt			ofmt
#define Ioldlastpm		oldlastpm
#define Ioldname		oldname
#define Iop_mask		op_mask
#define Iorigargc		origargc
#define Iorigargv		origargv
#define Iorigfilename		origfilename
#define Iors			ors
#define Iorslen			orslen
#define Iparsehook		parsehook
#define Ipatchlevel		patchlevel
#define Iperl_destruct_level	perl_destruct_level
#define Iperldb			perldb
#define Ipreambleav		preambleav
#define Ipreambled		preambled
#define Ipreprocess		preprocess
#define Irightgv		rightgv
#define Isawampersand		sawampersand
#define Isawstudy		sawstudy
#define Isawvec			sawvec
#define Iscreamfirst		screamfirst
#define Iscreamnext		screamnext
#define Isecondgv		secondgv
#define Isiggv			siggv
#define Isortcop		sortcop
#define Isortstash		sortstash
#define Isplitstr		splitstr
#define Istatcache		statcache
#define Istatgv			statgv
#define Istatname		statname
#define Istatusvalue		statusvalue
#define Istatusvalue_vms	statusvalue_vms
#define Istdingv		stdingv
#define Istrchop		strchop
#define Istrtab			strtab
#define Isv_arenaroot		sv_arenaroot
#define Isv_count		sv_count
#define Isv_objcount		sv_objcount
#define Isv_root		sv_root
#define Itainting		tainting
#define Ithreadnum		threadnum
#define Ithrsv			thrsv
#define Iunsafe			unsafe
#define Iwarnhook		warnhook

#ifndef USE_THREADS

#define TSv			Sv
#define TXpv			Xpv
#define Tav_fetch_sv		av_fetch_sv
#define Tbodytarget		bodytarget
#define Tchopset		chopset
#define Tcurcop			curcop
#define Tcurpad			curpad
#define Tcurpm			curpm
#define Tcurstack		curstack
#define Tcurstackinfo		curstackinfo
#define Tcurstash		curstash
#define Tdefoutgv		defoutgv
#define Tdefstash		defstash
#define Tdelaymagic		delaymagic
#define Tdirty			dirty
#define Tformtarget		formtarget
#define Thv_fetch_ent_mh	hv_fetch_ent_mh
#define Thv_fetch_sv		hv_fetch_sv
#define Tin_eval		in_eval
#define Tlast_in_gv		last_in_gv
#define Tlocalizing		localizing
#define Tmainstack		mainstack
#define Tmarkstack		markstack
#define Tmarkstack_max		markstack_max
#define Tmarkstack_ptr		markstack_ptr
#define Tnrs			nrs
#define Tofs			ofs
#define Tofslen			ofslen
#define Top			op
#define Topsave			opsave
#define Trestartop		restartop
#define Tretstack		retstack
#define Tretstack_ix		retstack_ix
#define Tretstack_max		retstack_max
#define Trs			rs
#define Tsavestack		savestack
#define Tsavestack_ix		savestack_ix
#define Tsavestack_max		savestack_max
#define Tscopestack		scopestack
#define Tscopestack_ix		scopestack_ix
#define Tscopestack_max		scopestack_max
#define Tstack_base		stack_base
#define Tstack_max		stack_max
#define Tstack_sp		stack_sp
#define Tstart_env		start_env
#define Tstatbuf		statbuf
#define Ttainted		tainted
#define Ttimesbuf		timesbuf
#define Ttmps_floor		tmps_floor
#define Ttmps_ix		tmps_ix
#define Ttmps_max		tmps_max
#define Ttmps_stack		tmps_stack
#define Ttop_env		top_env
#define Ttoptarget		toptarget

#endif /* USE_THREADS */

/* Hide what would have been interpreter-specific symbols? */

#ifdef EMBED

#define Argv			Perl_Argv
#define Cmd			Perl_Cmd
#define DBgv			Perl_DBgv
#define DBline			Perl_DBline
#define DBsignal		Perl_DBsignal
#define DBsingle		Perl_DBsingle
#define DBsub			Perl_DBsub
#define DBtrace			Perl_DBtrace
#define ampergv			Perl_ampergv
#define argvgv			Perl_argvgv
#define argvoutgv		Perl_argvoutgv
#define basetime		Perl_basetime
#define beginav			Perl_beginav
#define cddir			Perl_cddir
#define copline			Perl_copline
#define curcopdb		Perl_curcopdb
#define curstname		Perl_curstname
#define dbargs			Perl_dbargs
#define debdelim		Perl_debdelim
#define debname			Perl_debname
#define debstash		Perl_debstash
#define defgv			Perl_defgv
#define diehook			Perl_diehook
#define dlevel			Perl_dlevel
#define dlmax			Perl_dlmax
#define doextract		Perl_doextract
#define doswitches		Perl_doswitches
#define dowarn			Perl_dowarn
#define dumplvl			Perl_dumplvl
#define e_fp			Perl_e_fp
#define e_tmpname		Perl_e_tmpname
#define endav			Perl_endav
#define envgv			Perl_envgv
#define errgv			Perl_errgv
#define eval_root		Perl_eval_root
#define eval_start		Perl_eval_start
#define fdpid			Perl_fdpid
#define filemode		Perl_filemode
#define firstgv			Perl_firstgv
#define forkprocess		Perl_forkprocess
#define formfeed		Perl_formfeed
#define gensym			Perl_gensym
#define globalstash		Perl_globalstash
#define incgv			Perl_incgv
#define initav			Perl_initav
#define inplace			Perl_inplace
#define lastfd			Perl_lastfd
#define lastscream		Perl_lastscream
#define lastsize		Perl_lastsize
#define lastspbase		Perl_lastspbase
#define laststatval		Perl_laststatval
#define laststype		Perl_laststype
#define leftgv			Perl_leftgv
#define lineary			Perl_lineary
#define localpatches		Perl_localpatches
#define main_cv			Perl_main_cv
#define main_root		Perl_main_root
#define main_start		Perl_main_start
#define maxscream		Perl_maxscream
#define maxsysfd		Perl_maxsysfd
#define mess_sv			Perl_mess_sv
#define minus_F			Perl_minus_F
#define minus_a			Perl_minus_a
#define minus_c			Perl_minus_c
#define minus_l			Perl_minus_l
#define minus_n			Perl_minus_n
#define minus_p			Perl_minus_p
#define multiline		Perl_multiline
#define mystrk			Perl_mystrk
#define ofmt			Perl_ofmt
#define oldlastpm		Perl_oldlastpm
#define oldname			Perl_oldname
#define op_mask			Perl_op_mask
#define origargc		Perl_origargc
#define origargv		Perl_origargv
#define origfilename		Perl_origfilename
#define ors			Perl_ors
#define orslen			Perl_orslen
#define parsehook		Perl_parsehook
#define patchlevel		Perl_patchlevel
#define perl_destruct_level	Perl_perl_destruct_level
#define perldb			Perl_perldb
#define preambleav		Perl_preambleav
#define preambled		Perl_preambled
#define preprocess		Perl_preprocess
#define rightgv			Perl_rightgv
#define sawampersand		Perl_sawampersand
#define sawstudy		Perl_sawstudy
#define sawvec			Perl_sawvec
#define screamfirst		Perl_screamfirst
#define screamnext		Perl_screamnext
#define secondgv		Perl_secondgv
#define siggv			Perl_siggv
#define sortcop			Perl_sortcop
#define sortstash		Perl_sortstash
#define splitstr		Perl_splitstr
#define statcache		Perl_statcache
#define statgv			Perl_statgv
#define statname		Perl_statname
#define statusvalue		Perl_statusvalue
#define statusvalue_vms		Perl_statusvalue_vms
#define stdingv			Perl_stdingv
#define strchop			Perl_strchop
#define strtab			Perl_strtab
#define sv_arenaroot		Perl_sv_arenaroot
#define sv_count		Perl_sv_count
#define sv_objcount		Perl_sv_objcount
#define sv_root			Perl_sv_root
#define tainting		Perl_tainting
#define threadnum		Perl_threadnum
#define thrsv			Perl_thrsv
#define unsafe			Perl_unsafe
#define warnhook		Perl_warnhook

#ifndef USE_THREADS

#define Sv			Perl_Sv
#define Xpv			Perl_Xpv
#define av_fetch_sv		Perl_av_fetch_sv
#define bodytarget		Perl_bodytarget
#define chopset			Perl_chopset
#define curcop			Perl_curcop
#define curpad			Perl_curpad
#define curpm			Perl_curpm
#define curstack		Perl_curstack
#define curstackinfo		Perl_curstackinfo
#define curstash		Perl_curstash
#define defoutgv		Perl_defoutgv
#define defstash		Perl_defstash
#define delaymagic		Perl_delaymagic
#define dirty			Perl_dirty
#define formtarget		Perl_formtarget
#define hv_fetch_ent_mh		Perl_hv_fetch_ent_mh
#define hv_fetch_sv		Perl_hv_fetch_sv
#define in_eval			Perl_in_eval
#define last_in_gv		Perl_last_in_gv
#define localizing		Perl_localizing
#define mainstack		Perl_mainstack
#define markstack		Perl_markstack
#define markstack_max		Perl_markstack_max
#define markstack_ptr		Perl_markstack_ptr
#define nrs			Perl_nrs
#define ofs			Perl_ofs
#define ofslen			Perl_ofslen
#define op			Perl_op
#define opsave			Perl_opsave
#define restartop		Perl_restartop
#define retstack		Perl_retstack
#define retstack_ix		Perl_retstack_ix
#define retstack_max		Perl_retstack_max
#define rs			Perl_rs
#define savestack		Perl_savestack
#define savestack_ix		Perl_savestack_ix
#define savestack_max		Perl_savestack_max
#define scopestack		Perl_scopestack
#define scopestack_ix		Perl_scopestack_ix
#define scopestack_max		Perl_scopestack_max
#define stack_base		Perl_stack_base
#define stack_max		Perl_stack_max
#define stack_sp		Perl_stack_sp
#define start_env		Perl_start_env
#define statbuf			Perl_statbuf
#define tainted			Perl_tainted
#define timesbuf		Perl_timesbuf
#define tmps_floor		Perl_tmps_floor
#define tmps_ix			Perl_tmps_ix
#define tmps_max		Perl_tmps_max
#define tmps_stack		Perl_tmps_stack
#define top_env			Perl_top_env
#define toptarget		Perl_toptarget

#endif /* USE_THREADS */
#endif /* EMBED */
#endif /* MULTIPLICITY */

/* Now same trickey for per-thread variables */

#ifdef USE_THREADS

#define Sv			(thr->TSv)
#define Xpv			(thr->TXpv)
#define av_fetch_sv		(thr->Tav_fetch_sv)
#define bodytarget		(thr->Tbodytarget)
#define chopset			(thr->Tchopset)
#define curcop			(thr->Tcurcop)
#define curpad			(thr->Tcurpad)
#define curpm			(thr->Tcurpm)
#define curstack		(thr->Tcurstack)
#define curstackinfo		(thr->Tcurstackinfo)
#define curstash		(thr->Tcurstash)
#define defoutgv		(thr->Tdefoutgv)
#define defstash		(thr->Tdefstash)
#define delaymagic		(thr->Tdelaymagic)
#define dirty			(thr->Tdirty)
#define formtarget		(thr->Tformtarget)
#define hv_fetch_ent_mh		(thr->Thv_fetch_ent_mh)
#define hv_fetch_sv		(thr->Thv_fetch_sv)
#define in_eval			(thr->Tin_eval)
#define last_in_gv		(thr->Tlast_in_gv)
#define localizing		(thr->Tlocalizing)
#define mainstack		(thr->Tmainstack)
#define markstack		(thr->Tmarkstack)
#define markstack_max		(thr->Tmarkstack_max)
#define markstack_ptr		(thr->Tmarkstack_ptr)
#define nrs			(thr->Tnrs)
#define ofs			(thr->Tofs)
#define ofslen			(thr->Tofslen)
#define op			(thr->Top)
#define opsave			(thr->Topsave)
#define restartop		(thr->Trestartop)
#define retstack		(thr->Tretstack)
#define retstack_ix		(thr->Tretstack_ix)
#define retstack_max		(thr->Tretstack_max)
#define rs			(thr->Trs)
#define savestack		(thr->Tsavestack)
#define savestack_ix		(thr->Tsavestack_ix)
#define savestack_max		(thr->Tsavestack_max)
#define scopestack		(thr->Tscopestack)
#define scopestack_ix		(thr->Tscopestack_ix)
#define scopestack_max		(thr->Tscopestack_max)
#define stack_base		(thr->Tstack_base)
#define stack_max		(thr->Tstack_max)
#define stack_sp		(thr->Tstack_sp)
#define start_env		(thr->Tstart_env)
#define statbuf			(thr->Tstatbuf)
#define tainted			(thr->Ttainted)
#define timesbuf		(thr->Ttimesbuf)
#define tmps_floor		(thr->Ttmps_floor)
#define tmps_ix			(thr->Ttmps_ix)
#define tmps_max		(thr->Ttmps_max)
#define tmps_stack		(thr->Ttmps_stack)
#define top_env			(thr->Ttop_env)
#define toptarget		(thr->Ttoptarget)

#endif /* USE_THREADS */

#ifdef PERL_GLOBAL_STRUCT

#define No			(Perl_Vars.GNo)
#define Yes			(Perl_Vars.GYes)
#define amagic_generation	(Perl_Vars.Gamagic_generation)
#define an			(Perl_Vars.Gan)
#define bufend			(Perl_Vars.Gbufend)
#define bufptr			(Perl_Vars.Gbufptr)
#define collation_ix		(Perl_Vars.Gcollation_ix)
#define collation_name		(Perl_Vars.Gcollation_name)
#define collation_standard	(Perl_Vars.Gcollation_standard)
#define collxfrm_base		(Perl_Vars.Gcollxfrm_base)
#define collxfrm_mult		(Perl_Vars.Gcollxfrm_mult)
#define compcv			(Perl_Vars.Gcompcv)
#define compiling		(Perl_Vars.Gcompiling)
#define comppad			(Perl_Vars.Gcomppad)
#define comppad_name		(Perl_Vars.Gcomppad_name)
#define comppad_name_fill	(Perl_Vars.Gcomppad_name_fill)
#define comppad_name_floor	(Perl_Vars.Gcomppad_name_floor)
#define cop_seqmax		(Perl_Vars.Gcop_seqmax)
#define cryptseen		(Perl_Vars.Gcryptseen)
#define cshlen			(Perl_Vars.Gcshlen)
#define cshname			(Perl_Vars.Gcshname)
#define curinterp		(Perl_Vars.Gcurinterp)
#define curthr			(Perl_Vars.Gcurthr)
#define debug			(Perl_Vars.Gdebug)
#define do_undump		(Perl_Vars.Gdo_undump)
#define egid			(Perl_Vars.Gegid)
#define error_count		(Perl_Vars.Gerror_count)
#define euid			(Perl_Vars.Geuid)
#define eval_cond		(Perl_Vars.Geval_cond)
#define eval_mutex		(Perl_Vars.Geval_mutex)
#define eval_owner		(Perl_Vars.Geval_owner)
#define evalseq			(Perl_Vars.Gevalseq)
#define expect			(Perl_Vars.Gexpect)
#define gid			(Perl_Vars.Ggid)
#define he_root			(Perl_Vars.Ghe_root)
#define hexdigit		(Perl_Vars.Ghexdigit)
#define hints			(Perl_Vars.Ghints)
#define in_my			(Perl_Vars.Gin_my)
#define in_my_stash		(Perl_Vars.Gin_my_stash)
#define last_lop		(Perl_Vars.Glast_lop)
#define last_lop_op		(Perl_Vars.Glast_lop_op)
#define last_uni		(Perl_Vars.Glast_uni)
#define lex_brackets		(Perl_Vars.Glex_brackets)
#define lex_brackstack		(Perl_Vars.Glex_brackstack)
#define lex_casemods		(Perl_Vars.Glex_casemods)
#define lex_casestack		(Perl_Vars.Glex_casestack)
#define lex_defer		(Perl_Vars.Glex_defer)
#define lex_dojoin		(Perl_Vars.Glex_dojoin)
#define lex_expect		(Perl_Vars.Glex_expect)
#define lex_fakebrack		(Perl_Vars.Glex_fakebrack)
#define lex_formbrack		(Perl_Vars.Glex_formbrack)
#define lex_inpat		(Perl_Vars.Glex_inpat)
#define lex_inwhat		(Perl_Vars.Glex_inwhat)
#define lex_op			(Perl_Vars.Glex_op)
#define lex_repl		(Perl_Vars.Glex_repl)
#define lex_starts		(Perl_Vars.Glex_starts)
#define lex_state		(Perl_Vars.Glex_state)
#define lex_stuff		(Perl_Vars.Glex_stuff)
#define linestr			(Perl_Vars.Glinestr)
#define malloc_mutex		(Perl_Vars.Gmalloc_mutex)
#define max_intro_pending	(Perl_Vars.Gmax_intro_pending)
#define maxo			(Perl_Vars.Gmaxo)
#define min_intro_pending	(Perl_Vars.Gmin_intro_pending)
#define multi_close		(Perl_Vars.Gmulti_close)
#define multi_end		(Perl_Vars.Gmulti_end)
#define multi_open		(Perl_Vars.Gmulti_open)
#define multi_start		(Perl_Vars.Gmulti_start)
#define na			(Perl_Vars.Gna)
#define nexttoke		(Perl_Vars.Gnexttoke)
#define nexttype		(Perl_Vars.Gnexttype)
#define nextval			(Perl_Vars.Gnextval)
#define nice_chunk		(Perl_Vars.Gnice_chunk)
#define nice_chunk_size		(Perl_Vars.Gnice_chunk_size)
#define nomemok			(Perl_Vars.Gnomemok)
#define nthreads		(Perl_Vars.Gnthreads)
#define nthreads_cond		(Perl_Vars.Gnthreads_cond)
#define numeric_local		(Perl_Vars.Gnumeric_local)
#define numeric_name		(Perl_Vars.Gnumeric_name)
#define numeric_standard	(Perl_Vars.Gnumeric_standard)
#define oldbufptr		(Perl_Vars.Goldbufptr)
#define oldoldbufptr		(Perl_Vars.Goldoldbufptr)
#define op_seqmax		(Perl_Vars.Gop_seqmax)
#define origalen		(Perl_Vars.Gorigalen)
#define origenviron		(Perl_Vars.Gorigenviron)
#define osname			(Perl_Vars.Gosname)
#define pad_reset_pending	(Perl_Vars.Gpad_reset_pending)
#define padix			(Perl_Vars.Gpadix)
#define padix_floor		(Perl_Vars.Gpadix_floor)
#define patleave		(Perl_Vars.Gpatleave)
#define pidstatus		(Perl_Vars.Gpidstatus)
#define profiledata		(Perl_Vars.Gprofiledata)
#define rsfp			(Perl_Vars.Grsfp)
#define rsfp_filters		(Perl_Vars.Grsfp_filters)
#define runops			(Perl_Vars.Grunops)
#define scrgv			(Perl_Vars.Gscrgv)
#define sh_path			(Perl_Vars.Gsh_path)
#define sighandlerp		(Perl_Vars.Gsighandlerp)
#define sub_generation		(Perl_Vars.Gsub_generation)
#define subline			(Perl_Vars.Gsubline)
#define subname			(Perl_Vars.Gsubname)
#define sv_mutex		(Perl_Vars.Gsv_mutex)
#define sv_no			(Perl_Vars.Gsv_no)
#define sv_undef		(Perl_Vars.Gsv_undef)
#define sv_yes			(Perl_Vars.Gsv_yes)
#define svref_mutex		(Perl_Vars.Gsvref_mutex)
#define thisexpr		(Perl_Vars.Gthisexpr)
#define thr_key			(Perl_Vars.Gthr_key)
#define threads_mutex		(Perl_Vars.Gthreads_mutex)
#define threadsv_names		(Perl_Vars.Gthreadsv_names)
#define tokenbuf		(Perl_Vars.Gtokenbuf)
#define uid			(Perl_Vars.Guid)
#define xiv_arenaroot		(Perl_Vars.Gxiv_arenaroot)
#define xiv_root		(Perl_Vars.Gxiv_root)
#define xnv_root		(Perl_Vars.Gxnv_root)
#define xpv_root		(Perl_Vars.Gxpv_root)
#define xrv_root		(Perl_Vars.Gxrv_root)

#else /* !PERL_GLOBAL_STRUCT */

#define GNo			No
#define GYes			Yes
#define Gamagic_generation	amagic_generation
#define Gan			an
#define Gbufend			bufend
#define Gbufptr			bufptr
#define Gcollation_ix		collation_ix
#define Gcollation_name		collation_name
#define Gcollation_standard	collation_standard
#define Gcollxfrm_base		collxfrm_base
#define Gcollxfrm_mult		collxfrm_mult
#define Gcompcv			compcv
#define Gcompiling		compiling
#define Gcomppad		comppad
#define Gcomppad_name		comppad_name
#define Gcomppad_name_fill	comppad_name_fill
#define Gcomppad_name_floor	comppad_name_floor
#define Gcop_seqmax		cop_seqmax
#define Gcryptseen		cryptseen
#define Gcshlen			cshlen
#define Gcshname		cshname
#define Gcurinterp		curinterp
#define Gcurthr			curthr
#define Gdebug			debug
#define Gdo_undump		do_undump
#define Gegid			egid
#define Gerror_count		error_count
#define Geuid			euid
#define Geval_cond		eval_cond
#define Geval_mutex		eval_mutex
#define Geval_owner		eval_owner
#define Gevalseq		evalseq
#define Gexpect			expect
#define Ggid			gid
#define Ghe_root		he_root
#define Ghexdigit		hexdigit
#define Ghints			hints
#define Gin_my			in_my
#define Gin_my_stash		in_my_stash
#define Glast_lop		last_lop
#define Glast_lop_op		last_lop_op
#define Glast_uni		last_uni
#define Glex_brackets		lex_brackets
#define Glex_brackstack		lex_brackstack
#define Glex_casemods		lex_casemods
#define Glex_casestack		lex_casestack
#define Glex_defer		lex_defer
#define Glex_dojoin		lex_dojoin
#define Glex_expect		lex_expect
#define Glex_fakebrack		lex_fakebrack
#define Glex_formbrack		lex_formbrack
#define Glex_inpat		lex_inpat
#define Glex_inwhat		lex_inwhat
#define Glex_op			lex_op
#define Glex_repl		lex_repl
#define Glex_starts		lex_starts
#define Glex_state		lex_state
#define Glex_stuff		lex_stuff
#define Glinestr		linestr
#define Gmalloc_mutex		malloc_mutex
#define Gmax_intro_pending	max_intro_pending
#define Gmaxo			maxo
#define Gmin_intro_pending	min_intro_pending
#define Gmulti_close		multi_close
#define Gmulti_end		multi_end
#define Gmulti_open		multi_open
#define Gmulti_start		multi_start
#define Gna			na
#define Gnexttoke		nexttoke
#define Gnexttype		nexttype
#define Gnextval		nextval
#define Gnice_chunk		nice_chunk
#define Gnice_chunk_size	nice_chunk_size
#define Gnomemok		nomemok
#define Gnthreads		nthreads
#define Gnthreads_cond		nthreads_cond
#define Gnumeric_local		numeric_local
#define Gnumeric_name		numeric_name
#define Gnumeric_standard	numeric_standard
#define Goldbufptr		oldbufptr
#define Goldoldbufptr		oldoldbufptr
#define Gop_seqmax		op_seqmax
#define Gorigalen		origalen
#define Gorigenviron		origenviron
#define Gosname			osname
#define Gpad_reset_pending	pad_reset_pending
#define Gpadix			padix
#define Gpadix_floor		padix_floor
#define Gpatleave		patleave
#define Gpidstatus		pidstatus
#define Gprofiledata		profiledata
#define Grsfp			rsfp
#define Grsfp_filters		rsfp_filters
#define Grunops			runops
#define Gscrgv			scrgv
#define Gsh_path		sh_path
#define Gsighandlerp		sighandlerp
#define Gsub_generation		sub_generation
#define Gsubline		subline
#define Gsubname		subname
#define Gsv_mutex		sv_mutex
#define Gsv_no			sv_no
#define Gsv_undef		sv_undef
#define Gsv_yes			sv_yes
#define Gsvref_mutex		svref_mutex
#define Gthisexpr		thisexpr
#define Gthr_key		thr_key
#define Gthreads_mutex		threads_mutex
#define Gthreadsv_names		threadsv_names
#define Gtokenbuf		tokenbuf
#define Guid			uid
#define Gxiv_arenaroot		xiv_arenaroot
#define Gxiv_root		xiv_root
#define Gxnv_root		xnv_root
#define Gxpv_root		xpv_root
#define Gxrv_root		xrv_root

#ifdef EMBED

#define No			Perl_No
#define Yes			Perl_Yes
#define amagic_generation	Perl_amagic_generation
#define an			Perl_an
#define bufend			Perl_bufend
#define bufptr			Perl_bufptr
#define collation_ix		Perl_collation_ix
#define collation_name		Perl_collation_name
#define collation_standard	Perl_collation_standard
#define collxfrm_base		Perl_collxfrm_base
#define collxfrm_mult		Perl_collxfrm_mult
#define compcv			Perl_compcv
#define compiling		Perl_compiling
#define comppad			Perl_comppad
#define comppad_name		Perl_comppad_name
#define comppad_name_fill	Perl_comppad_name_fill
#define comppad_name_floor	Perl_comppad_name_floor
#define cop_seqmax		Perl_cop_seqmax
#define cryptseen		Perl_cryptseen
#define cshlen			Perl_cshlen
#define cshname			Perl_cshname
#define curinterp		Perl_curinterp
#define curthr			Perl_curthr
#define debug			Perl_debug
#define do_undump		Perl_do_undump
#define egid			Perl_egid
#define error_count		Perl_error_count
#define euid			Perl_euid
#define eval_cond		Perl_eval_cond
#define eval_mutex		Perl_eval_mutex
#define eval_owner		Perl_eval_owner
#define evalseq			Perl_evalseq
#define expect			Perl_expect
#define gid			Perl_gid
#define he_root			Perl_he_root
#define hexdigit		Perl_hexdigit
#define hints			Perl_hints
#define in_my			Perl_in_my
#define in_my_stash		Perl_in_my_stash
#define last_lop		Perl_last_lop
#define last_lop_op		Perl_last_lop_op
#define last_uni		Perl_last_uni
#define lex_brackets		Perl_lex_brackets
#define lex_brackstack		Perl_lex_brackstack
#define lex_casemods		Perl_lex_casemods
#define lex_casestack		Perl_lex_casestack
#define lex_defer		Perl_lex_defer
#define lex_dojoin		Perl_lex_dojoin
#define lex_expect		Perl_lex_expect
#define lex_fakebrack		Perl_lex_fakebrack
#define lex_formbrack		Perl_lex_formbrack
#define lex_inpat		Perl_lex_inpat
#define lex_inwhat		Perl_lex_inwhat
#define lex_op			Perl_lex_op
#define lex_repl		Perl_lex_repl
#define lex_starts		Perl_lex_starts
#define lex_state		Perl_lex_state
#define lex_stuff		Perl_lex_stuff
#define linestr			Perl_linestr
#define malloc_mutex		Perl_malloc_mutex
#define max_intro_pending	Perl_max_intro_pending
#define maxo			Perl_maxo
#define min_intro_pending	Perl_min_intro_pending
#define multi_close		Perl_multi_close
#define multi_end		Perl_multi_end
#define multi_open		Perl_multi_open
#define multi_start		Perl_multi_start
#define na			Perl_na
#define nexttoke		Perl_nexttoke
#define nexttype		Perl_nexttype
#define nextval			Perl_nextval
#define nice_chunk		Perl_nice_chunk
#define nice_chunk_size		Perl_nice_chunk_size
#define nomemok			Perl_nomemok
#define nthreads		Perl_nthreads
#define nthreads_cond		Perl_nthreads_cond
#define numeric_local		Perl_numeric_local
#define numeric_name		Perl_numeric_name
#define numeric_standard	Perl_numeric_standard
#define oldbufptr		Perl_oldbufptr
#define oldoldbufptr		Perl_oldoldbufptr
#define op_seqmax		Perl_op_seqmax
#define origalen		Perl_origalen
#define origenviron		Perl_origenviron
#define osname			Perl_osname
#define pad_reset_pending	Perl_pad_reset_pending
#define padix			Perl_padix
#define padix_floor		Perl_padix_floor
#define patleave		Perl_patleave
#define pidstatus		Perl_pidstatus
#define profiledata		Perl_profiledata
#define rsfp			Perl_rsfp
#define rsfp_filters		Perl_rsfp_filters
#define runops			Perl_runops
#define scrgv			Perl_scrgv
#define sh_path			Perl_sh_path
#define sighandlerp		Perl_sighandlerp
#define sub_generation		Perl_sub_generation
#define subline			Perl_subline
#define subname			Perl_subname
#define sv_mutex		Perl_sv_mutex
#define sv_no			Perl_sv_no
#define sv_undef		Perl_sv_undef
#define sv_yes			Perl_sv_yes
#define svref_mutex		Perl_svref_mutex
#define thisexpr		Perl_thisexpr
#define thr_key			Perl_thr_key
#define threads_mutex		Perl_threads_mutex
#define threadsv_names		Perl_threadsv_names
#define tokenbuf		Perl_tokenbuf
#define uid			Perl_uid
#define xiv_arenaroot		Perl_xiv_arenaroot
#define xiv_root		Perl_xiv_root
#define xnv_root		Perl_xnv_root
#define xpv_root		Perl_xpv_root
#define xrv_root		Perl_xrv_root

#endif /* EMBED */
#endif /* PERL_GLOBAL_STRUCT */

