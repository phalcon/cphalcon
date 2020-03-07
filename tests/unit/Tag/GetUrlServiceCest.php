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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use Phalcon\Url;
use UnitTester;

class GetUrlServiceCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: getUrlService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagGetUrlService(UnitTester $I)
    {
        $I->wantToTest('Tag - getUrlService()');

        $url = Tag::getUrlService();

        $I->assertInstanceOf(Url::class, $url);
        $I->assertInstanceOf(Url\UrlInterface::class, $url);
    }
}
