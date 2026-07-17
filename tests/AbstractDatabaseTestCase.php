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

namespace Phalcon\Tests;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Talon\PHPUnit\AbstractDatabaseTestCase as TalonAbstractDatabaseTestCase;
use Phalcon\Talon\Talon;

use function date;
use function getenv;
use function is_string;

abstract class AbstractDatabaseTestCase extends TalonAbstractDatabaseTestCase
{
    private static string $password = '';

    private static string $username = '';

    public static function getDatabaseDsn(): string
    {
        $driver   = self::getDatabaseDriver();
        $settings = Talon::settings();
        $options  = $settings->getDatabaseOptions($driver);

        self::$username = isset($options['username']) && is_string($options['username']) ? $options['username'] : '';
        self::$password = isset($options['password']) && is_string($options['password']) ? $options['password'] : '';

        return $settings->getDatabaseDsn($driver);
    }

    public static function getDatabaseNow(string $driver): string
    {
        return match ($driver) {
            'sqlite' => date("'Y-m-d H:i:s'"),
            default  => 'NOW()',
        };
    }

    /**
     * @return array<string, mixed>
     */
    public static function getDatabaseOptions(): array
    {
        return Talon::settings()->getDatabaseOptions(self::getDatabaseDriver());
    }

    public static function getDatabasePassword(): string
    {
        return self::$password;
    }

    public static function getDatabaseUsername(): string
    {
        return self::$username;
    }

    public static function getDataMapperConnection(): Connection
    {
        return new Connection(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );
    }

    /**
     * Named distinctly from Talon's inherited `getConnection(): ConnectionContract`
     * (not an override - PHP enforces covariant return types on an inherited
     * method, and `PDO` is unrelated to `ConnectionContract`). Reuses Talon's
     * cached, auto-schema-loaded connection under the hood.
     */
    public function getPdoConnection(): PDO
    {
        return $this->getConnection()->getPdo();
    }

    /**
     * Named distinctly from Talon's inherited, non-static `getDriver()`
     * (`DatabaseTrait::getDriver()`) - same collision reasoning as
     * `getPdoConnection()` above, but for a `static`-vs-instance mismatch
     * instead of a return-type mismatch: PHP does not allow an override to
     * change a method from non-static to static.
     */
    public static function getDatabaseDriver(): string
    {
        $driver = getenv('driver');

        return $driver !== false ? $driver : 'sqlite';
    }
}
