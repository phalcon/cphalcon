<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\Link;

use Phalcon\Link\Link;
use Psr\Link\LinkInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Link\Link :: __construct()
     *
     * @since  2019-06-15
     */
    public function linkLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Link\Link - __construct()');

        $link = new Link('payment', 'https://dev.cardoe.ld');

        $class = LinkInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
