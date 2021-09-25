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

class GetHrefCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: getHref()
     *
     * @since  2019-11-02
     */
    public function linkLinkGetHref(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Link - getHref()');

        $href = 'https://dev.phalcon.ld';
        $link = new Link('payment', $href);

        $I->assertEquals($href, $link->getHref());
    }
}
