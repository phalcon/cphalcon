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

namespace Phalcon\Tests\Unit\Html\Link\LinkProvider;

use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\LinkProvider;
use Phalcon\Html\Link\Interfaces\LinkProviderInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\LinkProvider
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\LinkProvider :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkLinkProviderConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\LinkProvider - __construct()');

        $links = [
            new Link('canonical', 'https://dev.phalcon.ld'),
            new Link('cite-as', 'https://test.phalcon.ld'),
        ];
        $link  = new LinkProvider($links);

        $class = LinkProviderInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
