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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

class GetSetOptionsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions() - constructor
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetOptionsConstructor(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getOptions()/setOptions() - constructor');

        $options = [
            'test1' => 'option1',
            'test2' => 'option2',
        ];

        $manager = new Manager($options);


        $I->assertEquals(
            $options,
            $manager->getOptions()
        );
    }

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetOptions(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getOptions()/setOptions()');

        $options = [
            'test1' => 'option1',
            'test2' => 'option2',
        ];

        $manager = new Manager($options);

        $options = [
            'test3' => 'option3',
        ];


        $manager->setOptions($options);

        $I->assertEquals(
            $options,
            $manager->getOptions()
        );
    }
}
