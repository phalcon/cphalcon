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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

/**
 * Class GetHrefCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLink
 */
class GetHrefCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: getHref()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkEvolvableLinkGetHref(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - getHref()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertEquals($href, $link->getHref());
    }
}
