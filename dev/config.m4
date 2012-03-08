PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework])

if test "$PHP_PHALCON" = "yes"; then
  AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon Framework])
  PHP_NEW_EXTENSION(phalcon, phalcon.c kernel/main.c kernel/fcall.c kernel/require.c kernel/debug.c kernel/assert.c kernel/object.c kernel/array.c dispatcher.c response.c request.c cache.c controller/front.c view.c cache/adapter/file.c cache/exception.c test.c utils.c db.c internal/test.c internal/testtemp.c internal/testdummy.c internal/testparent.c tag/exception.c router/rewrite.c db/exception.c db/mysql.c db/pool.c db/dialect/mysql.c db/rawvalue.c flash.c logger.c config.c filter.c exception.c transaction.c transaction/failed.c transaction/manager.c session.c config/adapter/ini.c config/exception.c controller.c model/message.c model/manager.c model/metadata.c model/row.c model/base.c model/metadata/memory.c model/resultset.c model/exception.c view/exception.c tag.c, $ext_shared)
fi
