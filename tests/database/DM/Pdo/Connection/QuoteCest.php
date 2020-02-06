<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;

class QuoteCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: quote()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionQuote(DatabaseTester $I)
    {
        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $quotes     = $connection->getQuoteNames();

        $source   = 'test';
        $expected = $quotes["prefix"] . $source . $quotes["suffix"];
        $actual   = $connection->quote($source);
        $I->assertEquals($expected, $actual);

        $source   = ['test', 1, true, null];
        $expected = $quotes["prefix"] . 'test' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '1' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '1' . $quotes["suffix"] . ', '
            . $quotes["prefix"] . '' . $quotes["suffix"];
        $actual   = $connection->quote($source);
        $I->assertEquals($expected, $actual);
    }
}
