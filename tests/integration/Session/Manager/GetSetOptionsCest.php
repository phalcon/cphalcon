<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

/**
 * Class GetSetOptionsCest
 */
class GetSetOptionsCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions() - constructor
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetOptionsConstructor(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getOptions()/setOptions() - constructor');
        $options = [
            'test1' => 'option1',
            'test2' => 'option2',
        ];

        $manager  = new Manager($options);
        $expected = $options;
        $actual   = $manager->getOptions();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
        $expected = $options;
        $actual   = $manager->getOptions();
        $I->assertEquals($expected, $actual);
    }
}
