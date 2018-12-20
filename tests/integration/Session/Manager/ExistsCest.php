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

use function cacheFolder;
use IntegrationTester;
use Phalcon\Session\Adapter\Files;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function uniqid;

/**
 * Class ExistsCest
 */
class ExistsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: exists()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerExists(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - exists()');
        $manager = new Manager();
        $files   = new Files(
            [
                'save_path' => cacheFolder()
            ]
        );
        $manager->setHandler($files);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $actual = $manager->exists();
        $I->assertTrue($actual);

        $actual = $manager->destroy();
        $I->assertTrue($actual);

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
