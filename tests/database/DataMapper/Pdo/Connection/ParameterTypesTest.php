<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use BadMethodCallException;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;
use PHPUnit\Framework\Attributes\IgnoreDeprecations;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/850
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ParameterTypesTest extends AbstractDatabaseTestCase
{
    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDMPdoConnectionUnderscoreCallInt(): void
    {
        $this->expectException(BadMethodCallException::class);
        $this->expectExceptionMessage(
            "Class 'Phalcon\\DataMapper\\Pdo\\Connection' does not have a method '5'"
        );

        self::getDataMapperConnection()->__call(5, []);
    }

    /**
     * method_exists() gives the deprecation "Passing null to parameter #2
     * ($method) of type string" for a null name.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[IgnoreDeprecations]
    public function testDMPdoConnectionUnderscoreCallNull(): void
    {
        $this->expectException(BadMethodCallException::class);
        $this->expectExceptionMessage(
            "Class 'Phalcon\\DataMapper\\Pdo\\Connection' does not have a method ''"
        );

        self::getDataMapperConnection()->__call(null, []);
    }
}
