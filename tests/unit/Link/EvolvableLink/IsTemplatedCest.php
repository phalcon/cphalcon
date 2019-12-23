<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\EvolvableLink;

use Phalcon\Link\EvolvableLink;
use UnitTester;

class IsTemplatedCest
{
    /**
     * Tests Phalcon\Link\Link :: isTemplated()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkIsTemplated(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLink - isTemplated()');

        $href = 'https://dev.cardoe.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertFalse($link->isTemplated());

        $href = 'https://dev.{domain}.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertTrue($link->isTemplated());
    }
}
