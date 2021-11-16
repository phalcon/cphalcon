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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Manager :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - __construct()');

        $manager = new Manager(new TagFactory(new Escaper()));

        $I->assertInstanceOf(Manager::class, $manager);
        $I->assertInstanceOf(InjectionAwareInterface::class, $manager);
    }
}
