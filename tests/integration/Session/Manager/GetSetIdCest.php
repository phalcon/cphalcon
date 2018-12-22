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
use function uniqid;

/**
 * Class GetSetIdCest
 */
class GetSetIdCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: getId()/setId()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetId(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getId()/setId()');
        $manager = new Manager();
        $files   = $this->getSessionFiles();
        $manager->setHandler($files);

        $expected = '';
        $actual   = $manager->getId();
        $I->assertEquals($expected, $actual);

        $id = uniqid();
        $manager->setId($id);
        $expected = $id;
        $actual   = $manager->getId();
        $I->assertEquals($expected, $actual);
        $manager->destroy();
    }
}
