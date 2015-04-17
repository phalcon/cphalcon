<<<<<<< HEAD
PHP_ARG_ENABLE(phalcon, whether to enable phalcon, [ --enable-phalcon   Enable Phalcon])

if test "$PHP_PHALCON" = "yes"; then
=======
PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework])
PHP_ARG_WITH(non-free, wheter to enable non-free css and js minifier, [ --without-non-free Disable non-free minifiers], yes, no)

AC_MSG_CHECKING([Include non-free minifiers])
if test "$PHP_NON_FREE" = "yes"; then
	AC_DEFINE([PHALCON_NON_FREE], [1], [Whether non-free minifiers are available])
	AC_MSG_RESULT([yes, css and js])
else
	AC_MSG_RESULT([no])
fi

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
mvc/collection/messageinterface.c \
mvc/collection/message.c \
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

	AC_MSG_CHECKING([Include non-free minifiers])
	if test "$PHP_NON_FREE" = "yes"; then
		phalcon_sources="$phalcon_sources assets/filters/jsminifier.c assets/filters/cssminifier.c "
	else
		phalcon_sources="$phalcon_sources assets/filters/nojsminifier.c assets/filters/nocssminifier.c "
	fi
>>>>>>> master

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCON_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon])
	phalcon_sources="phalcon.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalcon/acl.zep.c
	phalcon/acl/adapter.zep.c
	phalcon/acl/adapter/memory.zep.c
	phalcon/acl/adapterinterface.zep.c
	phalcon/acl/exception.zep.c
	phalcon/acl/resource.zep.c
	phalcon/acl/resourceinterface.zep.c
	phalcon/acl/role.zep.c
	phalcon/acl/roleinterface.zep.c
	phalcon/annotations/adapter.zep.c
	phalcon/annotations/adapter/apc.zep.c
	phalcon/annotations/adapter/files.zep.c
	phalcon/annotations/adapter/memory.zep.c
	phalcon/annotations/adapter/xcache.zep.c
	phalcon/annotations/adapterinterface.zep.c
	phalcon/annotations/annotation.zep.c
	phalcon/annotations/collection.zep.c
	phalcon/annotations/exception.zep.c
	phalcon/annotations/reader.zep.c
	phalcon/annotations/readerinterface.zep.c
	phalcon/annotations/reflection.zep.c
	phalcon/assets/collection.zep.c
	phalcon/assets/exception.zep.c
	phalcon/assets/filterinterface.zep.c
	phalcon/assets/filters/cssmin.zep.c
	phalcon/assets/filters/jsmin.zep.c
	phalcon/assets/filters/none.zep.c
	phalcon/assets/inline.zep.c
	phalcon/assets/inline/css.zep.c
	phalcon/assets/inline/js.zep.c
	phalcon/assets/manager.zep.c
	phalcon/assets/resource.zep.c
	phalcon/assets/resource/css.zep.c
	phalcon/assets/resource/js.zep.c
	phalcon/cache/backend.zep.c
	phalcon/cache/backend/apc.zep.c
	phalcon/cache/backend/file.zep.c
	phalcon/cache/backend/libmemcached.zep.c
	phalcon/cache/backend/memcache.zep.c
	phalcon/cache/backend/memory.zep.c
	phalcon/cache/backend/mongo.zep.c
	phalcon/cache/backend/redis.zep.c
	phalcon/cache/backend/xcache.zep.c
	phalcon/cache/backendinterface.zep.c
	phalcon/cache/exception.zep.c
	phalcon/cache/frontend/base64.zep.c
	phalcon/cache/frontend/data.zep.c
	phalcon/cache/frontend/igbinary.zep.c
	phalcon/cache/frontend/json.zep.c
	phalcon/cache/frontend/none.zep.c
	phalcon/cache/frontend/output.zep.c
	phalcon/cache/frontendinterface.zep.c
	phalcon/cache/multiple.zep.c
	phalcon/cli/console.zep.c
	phalcon/cli/console/exception.zep.c
	phalcon/cli/dispatcher.zep.c
	phalcon/cli/dispatcher/exception.zep.c
	phalcon/cli/router.zep.c
	phalcon/cli/router/exception.zep.c
	phalcon/cli/router/route.zep.c
	phalcon/cli/task.zep.c
	phalcon/config.zep.c
	phalcon/config/adapter/ini.zep.c
	phalcon/config/adapter/json.zep.c
	phalcon/config/adapter/php.zep.c
	phalcon/config/adapter/yaml.zep.c
	phalcon/config/exception.zep.c
	phalcon/crypt.zep.c
	phalcon/crypt/exception.zep.c
	phalcon/cryptinterface.zep.c
	phalcon/db.zep.c
	phalcon/db/adapter.zep.c
	phalcon/db/adapter/pdo.zep.c
	phalcon/db/adapter/pdo/mysql.zep.c
	phalcon/db/adapter/pdo/oracle.zep.c
	phalcon/db/adapter/pdo/postgresql.zep.c
	phalcon/db/adapter/pdo/sqlite.zep.c
	phalcon/db/adapterinterface.zep.c
	phalcon/db/column.zep.c
	phalcon/db/columninterface.zep.c
	phalcon/db/dialect.zep.c
	phalcon/db/dialect/mysql.zep.c
	phalcon/db/dialect/oracle.zep.c
	phalcon/db/dialect/postgresql.zep.c
	phalcon/db/dialect/sqlite.zep.c
	phalcon/db/dialectinterface.zep.c
	phalcon/db/exception.zep.c
	phalcon/db/index.zep.c
	phalcon/db/indexinterface.zep.c
	phalcon/db/profiler.zep.c
	phalcon/db/profiler/item.zep.c
	phalcon/db/rawvalue.zep.c
	phalcon/db/reference.zep.c
	phalcon/db/referenceinterface.zep.c
	phalcon/db/result/pdo.zep.c
	phalcon/db/resultinterface.zep.c
	phalcon/debug.zep.c
	phalcon/debug/dump.zep.c
	phalcon/debug/exception.zep.c
	phalcon/di.zep.c
	phalcon/di/exception.zep.c
	phalcon/di/factorydefault.zep.c
	phalcon/di/factorydefault/cli.zep.c
	phalcon/di/injectable.zep.c
	phalcon/di/injectionawareinterface.zep.c
	phalcon/di/service.zep.c
	phalcon/di/service/builder.zep.c
	phalcon/di/serviceinterface.zep.c
	phalcon/diinterface.zep.c
	phalcon/dispatcher.zep.c
	phalcon/dispatcherinterface.zep.c
	phalcon/escaper.zep.c
	phalcon/escaper/exception.zep.c
	phalcon/escaperinterface.zep.c
	phalcon/events/event.zep.c
	phalcon/events/eventsawareinterface.zep.c
	phalcon/events/exception.zep.c
	phalcon/events/manager.zep.c
	phalcon/events/managerinterface.zep.c
	phalcon/exception.zep.c
	phalcon/filter.zep.c
	phalcon/filter/exception.zep.c
	phalcon/filter/userfilterinterface.zep.c
	phalcon/filterinterface.zep.c
	phalcon/flash.zep.c
	phalcon/flash/direct.zep.c
	phalcon/flash/exception.zep.c
	phalcon/flash/session.zep.c
	phalcon/flashinterface.zep.c
	phalcon/forms/element.zep.c
	phalcon/forms/element/check.zep.c
	phalcon/forms/element/date.zep.c
	phalcon/forms/element/email.zep.c
	phalcon/forms/element/file.zep.c
	phalcon/forms/element/hidden.zep.c
	phalcon/forms/element/numeric.zep.c
	phalcon/forms/element/password.zep.c
	phalcon/forms/element/radio.zep.c
	phalcon/forms/element/select.zep.c
	phalcon/forms/element/submit.zep.c
	phalcon/forms/element/text.zep.c
	phalcon/forms/element/textarea.zep.c
	phalcon/forms/elementinterface.zep.c
	phalcon/forms/exception.zep.c
	phalcon/forms/form.zep.c
	phalcon/forms/manager.zep.c
	phalcon/http/cookie.zep.c
	phalcon/http/cookie/exception.zep.c
	phalcon/http/request.zep.c
	phalcon/http/request/exception.zep.c
	phalcon/http/request/file.zep.c
	phalcon/http/request/fileinterface.zep.c
	phalcon/http/requestinterface.zep.c
	phalcon/http/response.zep.c
	phalcon/http/response/cookies.zep.c
	phalcon/http/response/cookiesinterface.zep.c
	phalcon/http/response/exception.zep.c
	phalcon/http/response/headers.zep.c
	phalcon/http/response/headersinterface.zep.c
	phalcon/http/responseinterface.zep.c
	phalcon/image.zep.c
	phalcon/image/adapter.zep.c
	phalcon/image/adapter/gd.zep.c
	phalcon/image/adapter/imagick.zep.c
	phalcon/image/adapterinterface.zep.c
	phalcon/image/exception.zep.c
	phalcon/kernel.zep.c
	phalcon/loader.zep.c
	phalcon/loader/exception.zep.c
	phalcon/logger.zep.c
	phalcon/logger/adapter.zep.c
	phalcon/logger/adapter/file.zep.c
	phalcon/logger/adapter/firephp.zep.c
	phalcon/logger/adapter/stream.zep.c
	phalcon/logger/adapter/syslog.zep.c
	phalcon/logger/adapterinterface.zep.c
	phalcon/logger/exception.zep.c
	phalcon/logger/formatter.zep.c
	phalcon/logger/formatter/firephp.zep.c
	phalcon/logger/formatter/json.zep.c
	phalcon/logger/formatter/line.zep.c
	phalcon/logger/formatter/syslog.zep.c
	phalcon/logger/formatterinterface.zep.c
	phalcon/logger/item.zep.c
	phalcon/logger/multiple.zep.c
	phalcon/mvc/application.zep.c
	phalcon/mvc/application/exception.zep.c
	phalcon/mvc/collection.zep.c
	phalcon/mvc/collection/document.zep.c
	phalcon/mvc/collection/exception.zep.c
	phalcon/mvc/collection/manager.zep.c
	phalcon/mvc/collection/managerinterface.zep.c
	phalcon/mvc/collectioninterface.zep.c
	phalcon/mvc/controller.zep.c
	phalcon/mvc/controllerinterface.zep.c
	phalcon/mvc/dispatcher.zep.c
	phalcon/mvc/dispatcher/exception.zep.c
	phalcon/mvc/dispatcherinterface.zep.c
	phalcon/mvc/micro.zep.c
	phalcon/mvc/micro/collection.zep.c
	phalcon/mvc/micro/collectioninterface.zep.c
	phalcon/mvc/micro/exception.zep.c
	phalcon/mvc/micro/lazyloader.zep.c
	phalcon/mvc/micro/middlewareinterface.zep.c
	phalcon/mvc/model.zep.c
	phalcon/mvc/model/behavior.zep.c
	phalcon/mvc/model/behavior/softdelete.zep.c
	phalcon/mvc/model/behavior/timestampable.zep.c
	phalcon/mvc/model/behaviorinterface.zep.c
	phalcon/mvc/model/criteria.zep.c
	phalcon/mvc/model/criteriainterface.zep.c
	phalcon/mvc/model/exception.zep.c
	phalcon/mvc/model/manager.zep.c
	phalcon/mvc/model/managerinterface.zep.c
	phalcon/mvc/model/message.zep.c
	phalcon/mvc/model/messageinterface.zep.c
	phalcon/mvc/model/metadata.zep.c
	phalcon/mvc/model/metadata/apc.zep.c
	phalcon/mvc/model/metadata/files.zep.c
	phalcon/mvc/model/metadata/memory.zep.c
	phalcon/mvc/model/metadata/session.zep.c
	phalcon/mvc/model/metadata/strategy/annotations.zep.c
	phalcon/mvc/model/metadata/strategy/introspection.zep.c
	phalcon/mvc/model/metadata/strategyinterface.zep.c
	phalcon/mvc/model/metadata/xcache.zep.c
	phalcon/mvc/model/metadatainterface.zep.c
	phalcon/mvc/model/query.zep.c
	phalcon/mvc/model/query/builder.zep.c
	phalcon/mvc/model/query/builderinterface.zep.c
	phalcon/mvc/model/query/lang.zep.c
	phalcon/mvc/model/query/status.zep.c
	phalcon/mvc/model/query/statusinterface.zep.c
	phalcon/mvc/model/queryinterface.zep.c
	phalcon/mvc/model/relation.zep.c
	phalcon/mvc/model/relationinterface.zep.c
	phalcon/mvc/model/resultinterface.zep.c
	phalcon/mvc/model/resultset.zep.c
	phalcon/mvc/model/resultset/complex.zep.c
	phalcon/mvc/model/resultset/simple.zep.c
	phalcon/mvc/model/resultsetinterface.zep.c
	phalcon/mvc/model/row.zep.c
	phalcon/mvc/model/transaction.zep.c
	phalcon/mvc/model/transaction/exception.zep.c
	phalcon/mvc/model/transaction/failed.zep.c
	phalcon/mvc/model/transaction/manager.zep.c
	phalcon/mvc/model/transaction/managerinterface.zep.c
	phalcon/mvc/model/transactioninterface.zep.c
	phalcon/mvc/model/validationfailed.zep.c
	phalcon/mvc/model/validator.zep.c
	phalcon/mvc/model/validator/email.zep.c
	phalcon/mvc/model/validator/exclusionin.zep.c
	phalcon/mvc/model/validator/inclusionin.zep.c
	phalcon/mvc/model/validator/numericality.zep.c
	phalcon/mvc/model/validator/presenceof.zep.c
	phalcon/mvc/model/validator/regex.zep.c
	phalcon/mvc/model/validator/stringlength.zep.c
	phalcon/mvc/model/validator/uniqueness.zep.c
	phalcon/mvc/model/validator/url.zep.c
	phalcon/mvc/model/validatorinterface.zep.c
	phalcon/mvc/modelinterface.zep.c
	phalcon/mvc/moduledefinitioninterface.zep.c
	phalcon/mvc/router.zep.c
	phalcon/mvc/router/annotations.zep.c
	phalcon/mvc/router/exception.zep.c
	phalcon/mvc/router/group.zep.c
	phalcon/mvc/router/route.zep.c
	phalcon/mvc/router/routeinterface.zep.c
	phalcon/mvc/routerinterface.zep.c
	phalcon/mvc/url.zep.c
	phalcon/mvc/url/exception.zep.c
	phalcon/mvc/urlinterface.zep.c
	phalcon/mvc/user/component.zep.c
	phalcon/mvc/user/module.zep.c
	phalcon/mvc/user/plugin.zep.c
	phalcon/mvc/view.zep.c
	phalcon/mvc/view/engine.zep.c
	phalcon/mvc/view/engine/php.zep.c
	phalcon/mvc/view/engine/volt.zep.c
	phalcon/mvc/view/engine/volt/compiler.zep.c
	phalcon/mvc/view/engineinterface.zep.c
	phalcon/mvc/view/exception.zep.c
	phalcon/mvc/view/simple.zep.c
	phalcon/mvc/viewinterface.zep.c
	phalcon/paginator/adapter/model.zep.c
	phalcon/paginator/adapter/nativearray.zep.c
	phalcon/paginator/adapter/querybuilder.zep.c
	phalcon/paginator/adapterinterface.zep.c
	phalcon/paginator/exception.zep.c
	phalcon/queue/beanstalk.zep.c
	phalcon/queue/beanstalk/job.zep.c
	phalcon/registry.zep.c
	phalcon/security.zep.c
	phalcon/security/exception.zep.c
	phalcon/session.zep.c
	phalcon/session/adapter.zep.c
	phalcon/session/adapter/files.zep.c
	phalcon/session/adapter/libmemcached.zep.c
	phalcon/session/adapter/memcache.zep.c
	phalcon/session/adapterinterface.zep.c
	phalcon/session/bag.zep.c
	phalcon/session/baginterface.zep.c
	phalcon/session/exception.zep.c
	phalcon/tag.zep.c
	phalcon/tag/exception.zep.c
	phalcon/tag/select.zep.c
	phalcon/text.zep.c
	phalcon/translate.zep.c
	phalcon/translate/adapter.zep.c
	phalcon/translate/adapter/csv.zep.c
	phalcon/translate/adapter/gettext.zep.c
	phalcon/translate/adapter/nativearray.zep.c
	phalcon/translate/adapterinterface.zep.c
	phalcon/translate/exception.zep.c
	phalcon/validation.zep.c
	phalcon/validation/exception.zep.c
	phalcon/validation/message.zep.c
	phalcon/validation/message/group.zep.c
	phalcon/validation/messageinterface.zep.c
	phalcon/validation/validator.zep.c
	phalcon/validation/validator/alnum.zep.c
	phalcon/validation/validator/alpha.zep.c
	phalcon/validation/validator/between.zep.c
	phalcon/validation/validator/confirmation.zep.c
	phalcon/validation/validator/digit.zep.c
	phalcon/validation/validator/email.zep.c
	phalcon/validation/validator/exclusionin.zep.c
	phalcon/validation/validator/file.zep.c
	phalcon/validation/validator/identical.zep.c
	phalcon/validation/validator/inclusionin.zep.c
	phalcon/validation/validator/numericality.zep.c
	phalcon/validation/validator/presenceof.zep.c
	phalcon/validation/validator/regex.zep.c
	phalcon/validation/validator/stringlength.zep.c
	phalcon/validation/validator/uniqueness.zep.c
	phalcon/validation/validator/url.zep.c
	phalcon/validation/validatorinterface.zep.c
	phalcon/version.zep.c phalcon/annotations/scanner.c
	phalcon/annotations/parser.c
	phalcon/mvc/model/orm.c
	phalcon/mvc/model/query/scanner.c
	phalcon/mvc/model/query/parser.c
	phalcon/mvc/view/engine/volt/parser.c
	phalcon/mvc/view/engine/volt/scanner.c
	phalcon/assets/filters/jsminifier.c
	phalcon/assets/filters/cssminifier.c
	phalcon/mvc/url/utils.c"
	PHP_NEW_EXTENSION(phalcon, $phalcon_sources, $ext_shared,, )
	PHP_SUBST(PHALCON_SHARED_LIBADD)

	PHP_C_BIGENDIAN

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_HEADERS(
		[ext/json/php_json.h],
		[
			PHP_ADD_EXTENSION_DEP([phalcon], [json])
			AC_DEFINE([PHALCON_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
		],
		,
		[[#include "main/php.h"]]
	)


	AC_CHECK_DECL(
		[HAVE_PHP_SESSION],
		[
			AC_CHECK_HEADERS(
				[ext/session/php_session.h],
				[
<<<<<<< HEAD
					PHP_ADD_EXTENSION_DEP([phalcon], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
=======
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
>>>>>>> master
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

<<<<<<< HEAD
	PHP_INSTALL_HEADERS([ext/phalcon], [php_PHALCON.h])

=======
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
>>>>>>> master
fi
