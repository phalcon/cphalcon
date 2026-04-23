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

namespace Phalcon\Tests\Unit\Session\Manager;

use Phalcon\Session\Manager;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\SessionTrait;

final class ExistsDestroyTest extends AbstractUnitTestCase
{
    use DiTrait;
    use SessionTrait;

    /**
     * @dataProvider getClassNames
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12326
     * @issue  https://github.com/phalcon/cphalcon/issues/12835
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testSessionManagerDestroySuperGlobal(
        string $name
    ): void {
        $store    = $_SESSION ?? [];
        $_SESSION = [];

        $manager = new Manager();
        $files   = $this->newService($name);
        $manager->setAdapter($files);

        $actual = $manager->start();
        $this->assertTrue($actual);

        $actual = $manager->exists();
        $this->assertTrue($actual);

        $manager->set('test1', __METHOD__);
        $this->assertArrayHasKey('test1', $_SESSION);
        $this->assertStringContainsString(__METHOD__, $_SESSION['test1']);

        $manager->destroy();
        $this->assertArrayNotHasKey('test1', $_SESSION);

        $actual = $manager->exists();
        $this->assertFalse($actual);

        $_SESSION = $store;
    }

    /**
     * @dataProvider getClassNames
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSessionManagerDestroySuperGlobalUniquid(
        string $name
    ): void {
        $store    = $_SESSION ?? [];
        $_SESSION = [];

        $manager = new Manager();
        $files   = $this->newService($name);
        $manager->setAdapter($files);
        $manager->setOptions(
            [
                'uniqueId' => 'aaa',
            ]
        );

        $actual = $manager->start();
        $this->assertTrue($actual);

        $actual = $manager->exists();
        $this->assertTrue($actual);

        $manager->set('test1', __METHOD__);

        $this->assertArrayHasKey('aaa#test1', $_SESSION);
        $this->assertStringContainsString(__METHOD__, $_SESSION['aaa#test1']);

        $manager->destroy();
        $this->assertArrayNotHasKey('aaa#test1', $_SESSION);

        $actual = $manager->exists();
        $this->assertFalse($actual);

        $_SESSION = $store;
    }

    /**
     * @dataProvider getClassNames
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testSessionManagerExistsDestroy(
        string $name
    ): void {
        $store    = $_SESSION ?? [];
        $_SESSION = [];

        $manager = new Manager();
        $files   = $this->newService($name);
        $manager->setAdapter($files);

        $actual = $manager->start();
        $this->assertTrue($actual);

        $actual = $manager->exists();
        $this->assertTrue($actual);

        $manager->destroy();

        $actual = $manager->exists();
        $this->assertFalse($actual);

        $_SESSION = $store;
    }
}
