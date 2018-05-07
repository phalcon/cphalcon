<?php

namespace Helper\Db\Connection;

use Phalcon\Db\Adapter\Pdo\Sqlite;

/**
 * Helper\Db\Connection\SqliteTranslationsFactory
 *
 * @package Helper\Db\Connection
 */
class SqlitetranslationsFactory extends AbstractFactory
{
    /**
     * {@inheritdoc}
     *
     * @return Sqlite
     */
    public function createConnection()
    {
        return new Sqlite(
            ['dbname' => env('TEST_DB_I18N_SQLITE_NAME', PATH_OUTPUT . 'translations.sqlite')]
        );
    }
}
