<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Traits;

use DatabaseTester;
use PDO;
use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cache\Adapter\Libmemcached as StorageLibmemcached;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Crypt;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Escaper;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\Metadata\Memory as MetadataMemory;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Simple;
use Phalcon\Session\Adapter\Libmemcached as SessionLibmemcached;
use Phalcon\Session\Adapter\Noop as SessionNoop;
use Phalcon\Session\Adapter\Redis as SessionRedis;
use Phalcon\Session\Adapter\Stream as SessionFiles;
use Phalcon\Session\Manager as SessionManager;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Url;
use function dataDir;
use function getOptionsLibmemcached;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsRedis;
use function getOptionsSqlite;
use function uniqid;

trait RecordsTrait
{
    /**
     * @param int $number
     *
     * @return false|float
     */
    private function getFibonacci(int $number)
    {
        return round(pow((sqrt(5) + 1) / 2, $number) / sqrt(5));
    }

    /**
     * @param InvoicesMigration $migration
     * @param int               $count
     * @param string            $invId
     * @param int               $custId
     * @param string            $prefix
     * @param int               $pad
     */
    private function insertDataInvoices(
        InvoicesMigration $migration,
        int $count,
        string $invId = null,
        int $custId,
        string $prefix,
        int $pad = 0
    ) {
        $title = uniqid($prefix . '-');
        for ($counter = 1; $counter <= $count; $counter++) {
            $migration->insert(
                $invId,
                $custId,
                1,
                $title,
                $this->getFibonacci($pad + $counter)
            );
        }
    }
}
