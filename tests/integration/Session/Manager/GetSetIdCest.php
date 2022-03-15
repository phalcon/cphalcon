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

namespace Phalcon\Tests\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Exception;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function uniqid;

class GetSetIdCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: getId()/setId()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerGetSetId(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getId()/setId()');

        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->getId();
        $I->assertEquals('', $actual);

        $id = uniqid();
        $manager->setId($id);

        $actual = $manager->getId();
        $I->assertEquals($id, $actual);

        $manager->destroy();
    }

    /**
     * Tests Phalcon\Session\Manager :: setId() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerSetIdException(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - setId() - exception');

        $I->expectThrowable(
            new Exception(
                'The session has already been started. ' .
                'To change the id, use regenerateId()'
            ),
            function () {
                $manager = new Manager();
                $files   = $this->newService('sessionStream');
                $manager->setAdapter($files);

                $manager->start();

                $id = uniqid();
                $manager->setId($id);
            }
        );
    }
}
