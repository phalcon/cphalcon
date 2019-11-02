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

namespace Phalcon\Test\Unit\Html\Link\LinkProvider;

use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\LinkProvider;
use Psr\Link\LinkProviderInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\LinkProvider :: __construct()
     *
     * @since  2019-06-15
     */
    public function linkLinkProviderConstruct(UnitTester $I)
    {
        $I->wantToTest('Link\LinkProvider - __construct()');

        $links = [
            new Link('canonical', 'https://dev.phalcon.ld'),
            new Link('cite-as', 'https://test.phalcon.ld'),
        ];
        $link  = new LinkProvider($links);

        $class = LinkProviderInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
