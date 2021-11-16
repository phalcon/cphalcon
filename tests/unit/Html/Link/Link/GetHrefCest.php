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
use UnitTester;

/**
 * Class GetHrefCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\Link
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
    public function linkLinkGetHref(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Link - getHref()');

        $href = 'https://dev.phalcon.ld';
        $link = new Link('payment', $href);

        $I->assertEquals($href, $link->getHref());
    }
}
