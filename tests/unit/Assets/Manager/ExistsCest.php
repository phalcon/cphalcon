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
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use UnitTester;

class ExistsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: exists()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerExists(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - exists()');

        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('/css/style1.css');
        $manager->addCss('/css/style2.css');

        $I->assertTrue($manager->exists('css'));
    }

    /**
     * Tests Phalcon\Assets\Manager :: exists() - empty
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerExistsEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - exists() - empty');

        $manager = new Manager(new TagFactory(new Escaper()));

        $I->assertFalse($manager->exists('some-non-existent-collection'));
    }
}
