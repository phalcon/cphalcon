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

namespace Phalcon\Tests\Unit\Html\Link\Link;

use Phalcon\Html\Link\Link;
use Psr\Link\LinkInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\Link
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Link - __construct()');

        $link = new Link('payment', 'https://dev.phalcon.ld');

        $class = LinkInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
