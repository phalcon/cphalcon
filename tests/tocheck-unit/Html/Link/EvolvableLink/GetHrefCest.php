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

class GetHrefCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: getHref()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkGetHref(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - getHref()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertEquals($href, $link->getHref());
    }
}
