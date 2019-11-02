<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

class IsTemplatedCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: isTemplated()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkIsTemplated(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLink - isTemplated()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertFalse($link->isTemplated());

        $href = 'https://dev.{domain}.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertTrue($link->isTemplated());
    }
}
