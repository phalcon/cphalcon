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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

class WithHrefCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: withHref()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkWithHref(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - withHref()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertEquals($href, $link->getHref());

        $href        = 'https://test.phalcon.ld';
        $newInstance = $link->withHref($href);

        $I->assertNotSame($link, $newInstance);

        $I->assertEquals($href, $newInstance->getHref());
    }
}
