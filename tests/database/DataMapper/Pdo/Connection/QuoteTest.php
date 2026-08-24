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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class QuoteTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionQuote(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $quotes     = $connection->getQuoteNames();

        $source   = 'test';
        $expected = $quotes["prefix"] . $source . $quotes["suffix"];
        $actual   = $connection->quote($source);
        $this->assertEquals($expected, $actual);

        $source   = ['test', 1, true, null];
        $expected = $quotes["prefix"] . 'test' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '1' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '1' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '' . $quotes["suffix"];
        $actual   = $connection->quote($source);
        $this->assertEquals($expected, $actual);
    }

    /**
     * quote() must double the delimiter inside the value so an embedded
     * quote/backtick cannot break out of the identifier (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function testDMPdoConnectionQuoteEscapesDelimiter(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $quotes     = $connection->getQuoteNames();

        $source   = 'a' . $quotes["find"] . 'b';
        $escaped  = str_replace($quotes["find"], $quotes["replace"], $source);
        $expected = $quotes["prefix"] . $escaped . $quotes["suffix"];
        $actual   = $connection->quote($source);
        $this->assertEquals($expected, $actual);
    }
}
