PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework])

if test "$PHP_PHALCON" = "yes"; then
	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon Framework])
	phalcon_sources="phalcon.c \
kernel/main.c \
kernel/fcall.c \
kernel/require.c \
kernel/debug.c \
kernel/backtrace.c \
kernel/object.c \
kernel/array.c \
kernel/hash.c \
kernel/string.c \
kernel/mbstring.c \
kernel/filter.c \
kernel/operators.c \
kernel/concat.c \
kernel/exception.c \
kernel/file.c \
kernel/output.c \
kernel/memory.c \
kernel/session.c \
kernel/variables.c \
kernel/framework/orm.c \
kernel/framework/router.c \
kernel/framework/url.c \
interned-strings.c \
logger.c \
flash.c \
cli/dispatcher/exception.c \
cli/console.c \
cli/router.c \
cli/task.c \
cli/router/exception.c \
cli/dispatcher.c \
cli/console/exception.c \
security/exception.c \
db/dialect/sqlite.c \
db/dialect/mysql.c \
db/dialect/oracle.c \
db/dialect/postgresql.c \
db/result/pdo.c \
db/column.c \
db/index.c \
db/profiler/item.c \
db/indexinterface.c \
db/dialectinterface.c \
db/resultinterface.c \
db/profiler.c \
db/referenceinterface.c \
db/adapter/pdo/sqlite.c \
db/adapter/pdo/mysql.c \
db/adapter/pdo/oracle.c \
db/adapter/pdo/postgresql.c \
db/adapter/pdo.c \
db/exception.c \
db/reference.c \
db/adapterinterface.c \
db/dialect.c \
db/adapter.c \
db/rawvalue.c \
db/columninterface.c \
forms/form.c \
forms/manager.c \
forms/element/file.c \
forms/element/email.c \
forms/element/hidden.c \
forms/element/password.c \
forms/element/text.c \
forms/element/select.c \
forms/element/textarea.c \
forms/element/check.c \
forms/element/radio.c \
forms/element/numeric.c \
forms/element/submit.c \
forms/element/date.c \
forms/exception.c \
forms/element.c \
forms/elementinterface.c \
http/response.c \
http/requestinterface.c \
http/request.c \
http/cookie.c \
http/request/file.c \
http/request/exception.c \
http/request/fileinterface.c \
http/responseinterface.c \
http/cookie/exception.c \
http/response/cookies.c \
http/response/exception.c \
http/response/headers.c \
http/response/cookiesinterface.c \
http/response/headersinterface.c \
dispatcherinterface.c \
di.c \
loader/exception.c \
cryptinterface.c \
db.c \
text.c \
debug.c \
tag.c \
mvc/controller.c \
mvc/dispatcher/exception.c \
mvc/application/exception.c \
mvc/router.c \
mvc/micro.c \
mvc/micro/middlewareinterface.c \
mvc/micro/lazyloader.c \
mvc/micro/exception.c \
mvc/micro/collection.c \
mvc/micro/collectioninterface.c \
mvc/dispatcherinterface.c \
mvc/collection/managerinterface.c \
mvc/collection/manager.c \
mvc/collection/exception.c \
mvc/collection/document.c \
mvc/routerinterface.c \
mvc/urlinterface.c \
mvc/user/component.c \
mvc/user/plugin.c \
mvc/user/module.c \
mvc/url.c \
mvc/model.c \
mvc/view.c \
mvc/modelinterface.c \
mvc/router/group.c \
mvc/router/route.c \
mvc/router/annotations.c \
mvc/router/exception.c \
mvc/router/routeinterface.c \
mvc/url/exception.c \
mvc/viewinterface.c \
mvc/collection.c \
mvc/dispatcher.c \
mvc/collectioninterface.c \
mvc/view/engine/php.c \
mvc/view/engine/volt/compiler.c \
mvc/view/engine/volt.c \
mvc/view/engine/helpers.c \
mvc/view/exception.c \
mvc/view/engineinterface.c \
mvc/view/simple.c \
mvc/view/engine.c \
mvc/application.c \
mvc/controllerinterface.c \
mvc/moduledefinitioninterface.c \
mvc/model/metadata/files.c \
mvc/model/metadata/strategy/introspection.c \
mvc/model/metadata/strategy/annotations.c \
mvc/model/metadata/apc.c \
mvc/model/metadata/xcache.c \
mvc/model/metadata/memory.c \
mvc/model/metadata/session.c \
mvc/model/transaction.c \
mvc/model/validatorinterface.c \
mvc/model/metadata.c \
mvc/model/resultsetinterface.c \
mvc/model/managerinterface.c \
mvc/model/behavior.c \
mvc/model/query/builder.c \
mvc/model/query/lang.c \
mvc/model/query/statusinterface.c \
mvc/model/query/status.c \
mvc/model/query/builderinterface.c \
mvc/model/resultinterface.c \
mvc/model/criteriainterface.c \
mvc/model/query.c \
mvc/model/resultset.c \
mvc/model/validationfailed.c \
mvc/model/manager.c \
mvc/model/behaviorinterface.c \
mvc/model/relation.c \
mvc/model/exception.c \
mvc/model/message.c \
mvc/model/transaction/failed.c \
mvc/model/transaction/managerinterface.c \
mvc/model/transaction/manager.c \
mvc/model/transaction/exception.c \
mvc/model/queryinterface.c \
mvc/model/row.c \
mvc/model/criteria.c \
mvc/model/validator/email.c \
mvc/model/validator/presenceof.c \
mvc/model/validator/inclusionin.c \
mvc/model/validator/exclusionin.c \
mvc/model/validator/uniqueness.c \
mvc/model/validator/url.c \
mvc/model/validator/regex.c \
mvc/model/validator/numericality.c \
mvc/model/validator/stringlength.c \
mvc/model/resultset/complex.c \
mvc/model/resultset/simple.c \
mvc/model/behavior/timestampable.c \
mvc/model/behavior/softdelete.c \
mvc/model/validator.c \
mvc/model/metadatainterface.c \
mvc/model/relationinterface.c \
mvc/model/messageinterface.c \
mvc/model/transactioninterface.c \
config/adapter/ini.c \
config/adapter/json.c \
config/adapter/php.c \
config/adapter/yaml.c \
config/exception.c \
filterinterface.c \
logger/multiple.c \
logger/formatter/firephp.c \
logger/formatter/json.c \
logger/formatter/line.c \
logger/formatter/syslog.c \
logger/formatter.c \
logger/adapter/file.c \
logger/adapter/firephp.c \
logger/adapter/stream.c \
logger/adapter/syslog.c \
logger/exception.c \
logger/adapterinterface.c \
logger/formatterinterface.c \
logger/adapter.c \
logger/item.c \
filter/exception.c \
filter/userfilterinterface.c \
queue/beanstalk.c \
queue/beanstalk/job.c \
acl.c \
assets/resource/css.c \
assets/resource/js.c \
assets/filters/none.c \
assets/filters/cssmin.c \
assets/filters/jsmin.c \
assets/filterinterface.c \
assets/resource.c \
assets/manager.c \
assets/exception.c \
assets/collection.c \
escaper/exception.c \
loader.c \
tag/select.c \
tag/exception.c \
acl/resource.c \
acl/resourceinterface.c \
acl/adapter/memory.c \
acl/exception.c \
acl/role.c \
acl/adapterinterface.c \
acl/adapter.c \
acl/roleinterface.c \
exception.c \
crypt.c \
filter.c \
dispatcher.c \
cache/multiple.c \
cache/frontend/none.c \
cache/frontend/base64.c \
cache/frontend/json.c \
cache/frontend/igbinary.c \
cache/frontend/data.c \
cache/frontend/output.c \
cache/backend/file.c \
cache/backend/apc.c \
cache/backend/xcache.c \
cache/backend/mongo.c \
cache/backend/memcache.c \
cache/backend/libmemcached.c \
cache/backend/memory.c \
cache/exception.c \
cache/backendinterface.c \
cache/frontendinterface.c \
cache/backend.c \
session/bag.c \
session/adapter/files.c \
session/exception.c \
session/baginterface.c \
session/adapterinterface.c \
session/adapter.c \
session/adapter/memcache.c \
session/adapter/libmemcached.c \
diinterface.c \
escaper.c \
crypt/exception.c \
config.c \
events/managerinterface.c \
events/manager.c \
events/event.c \
events/exception.c \
events/eventsawareinterface.c \
escaperinterface.c \
validation.c \
version.c \
flashinterface.c \
kernel.c \
paginator/adapter/model.c \
paginator/adapter/nativearray.c \
paginator/adapter/querybuilder.c \
paginator/exception.c \
paginator/adapterinterface.c \
di/injectable.c \
di/factorydefault.c \
di/service/builder.c \
di/serviceinterface.c \
di/factorydefault/cli.c \
di/exception.c \
di/injectionawareinterface.c \
di/service.c \
security.c \
annotations/reflection.c \
annotations/annotation.c \
annotations/readerinterface.c \
annotations/adapter/files.c \
annotations/adapter/apc.c \
annotations/adapter/xcache.c \
annotations/adapter/memory.c \
annotations/exception.c \
annotations/collection.c \
annotations/adapterinterface.c \
annotations/adapter.c \
annotations/reader.c \
flash/direct.c \
flash/exception.c \
flash/session.c \
translate/adapter/nativearray.c \
translate/exception.c \
translate/adapterinterface.c \
translate/adapter.c \
translate/adapter/gettext.c \
validation/validatorinterface.c \
validation/message/group.c \
validation/exception.c \
validation/message.c \
validation/messageinterface.c \
validation/validator/email.c \
validation/validator/presenceof.c \
validation/validator/confirmation.c \
validation/validator/regex.c \
validation/validator/exclusionin.c \
validation/validator/identical.c \
validation/validator/between.c \
validation/validator/inclusionin.c \
validation/validator/stringlength.c \
validation/validator/url.c \
validation/validator.c \
assets/filters/jsminifier.c \
assets/filters/cssminifier.c \
mvc/model/query/parser.c \
mvc/model/query/scanner.c \
mvc/view/engine/volt/parser.c \
mvc/view/engine/volt/scanner.c \
annotations/parser.c \
annotations/scanner.c \
image.c \
image/adapter.c \
image/adapterinterface.c \
image/exception.c \
image/adapter/gd.c \
image/adapter/imagick.c \
psr/log/abstractlogger.c \
psr/log/invalidargumentexception.c \
psr/log/loggerawareinterface.c \
psr/log/loggerawaretrait.c \
psr/log/loggerinterface.c \
psr/log/loggertrait.c \
psr/log/loglevel.c \
psr/log/nulllogger.c \
registry.c"

	PHP_NEW_EXTENSION(phalcon, $phalcon_sources, $ext_shared)
	PHP_ADD_EXTENSION_DEP([phalcon], [spl])

	PHP_C_BIGENDIAN

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_HEADERS(
		[ext/igbinary/igbinary.h],
		[
			PHP_ADD_EXTENSION_DEP([phalcon], [igbinary])
			AC_DEFINE([PHALCON_USE_PHP_IGBINARY], [1], [Whether PHP igbinary extension is present at compile time])
		],
		,
		[[#include "main/php.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([PHALCON_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [json])
					AC_DEFINE([PHALCON_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_PHP_SESSION],
		[
			AC_CHECK_HEADERS(
				[ext/session/php_session.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [session])
					AC_DEFINE([PHALCON_USE_PHP_SESSION], [1], [Whether PHP session extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_HASH_EXT],
		[
			AC_CHECK_HEADERS(
				[ext/hash/php_hash.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [hash])
					AC_DEFINE([PHALCON_USE_PHP_HASH], [1], [Whether PHP hash extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag])
fi

PHP_ARG_ENABLE(coverage,  whether to include code coverage symbols,
[  --enable-coverage         Enable code coverage symbols, maintainers only!], no, no)

if test "$PHP_COVERAGE" = "yes"; then
	if test "$GCC" != "yes"; then
		AC_MSG_ERROR([GCC is required for --enable-coverage])
	fi

	case `$php_shtool path $CC` in
		*ccache*[)] gcc_ccache=yes;;
		*[)] gcc_ccache=no;;
	esac

	if test "$gcc_ccache" = "yes" && (test -z "$CCACHE_DISABLE" || test "$CCACHE_DISABLE" != "1"); then
		AC_MSG_ERROR([ccache must be disabled when --enable-coverage option is used. You can disable ccache by setting environment variable CCACHE_DISABLE=1.])
	fi

	lcov_version_list="1.5 1.6 1.7 1.9 1.10"

	AC_CHECK_PROG(LCOV, lcov, lcov)
	AC_CHECK_PROG(GENHTML, genhtml, genhtml)
	PHP_SUBST(LCOV)
	PHP_SUBST(GENHTML)

	if test "$LCOV"; then
		AC_CACHE_CHECK([for lcov version], php_cv_lcov_version, [
			php_cv_lcov_version=invalid
			lcov_version=`$LCOV -v 2>/dev/null | $SED -e 's/^.* //'` #'
			for lcov_check_version in $lcov_version_list; do
				if test "$lcov_version" = "$lcov_check_version"; then
					php_cv_lcov_version="$lcov_check_version (ok)"
				fi
			done
		])
	else
		lcov_msg="To enable code coverage reporting you must have one of the following LCOV versions installed: $lcov_version_list"
		AC_MSG_ERROR([$lcov_msg])
	fi

	case $php_cv_lcov_version in
		""|invalid[)]
			lcov_msg="You must have one of the following versions of LCOV: $lcov_version_list (found: $lcov_version)."
			AC_MSG_ERROR([$lcov_msg])
			LCOV="exit 0;"
		;;
	esac

	if test -z "$GENHTML"; then
		AC_MSG_ERROR([Could not find genhtml from the LCOV package])
	fi

	changequote({,})
	CFLAGS=`echo "$CFLAGS" | $SED -e 's/-O[0-9s]*//g'`
	CXXFLAGS=`echo "$CXXFLAGS" | $SED -e 's/-O[0-9s]*//g'`
	changequote([,])

	CFLAGS="$CFLAGS -O0 --coverage"
	CXXFLAGS="$CXXFLAGS -O0 --coverage"
	EXTRA_LDFLAGS="$EXTRA_LDFLAGS -precious-files-regex \.gcno\\\$$"

	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag.coverage])
fi

if test "$GCC" = "yes"; then
	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag.deps])
fi