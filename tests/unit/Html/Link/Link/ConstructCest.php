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

namespace Phalcon\Test\Unit\Html\Link\Link;

use Phalcon\Html\Link\Link;
use Psr\Link\LinkInterface;
use UnitTester;
use function var_dump;

class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: __construct()
     *
     * @since  2019-11-02
     */
    public function linkLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Link - __construct()');

        $link = new Link('payment', 'https://dev.phalcon.ld');

        $class = LinkInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
