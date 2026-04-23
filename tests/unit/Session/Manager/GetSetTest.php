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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class GetSetTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionManagerGetSet(): void
    {
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->get('test');
        $this->assertNull($actual);

        $actual = $manager->start();
        $this->assertTrue($actual);

        $expected = 'myval';
        $manager->set('test', $expected);

        $actual = $manager->get('test');
        $this->assertEquals($expected, $actual);

        $actual = $manager->has('test');
        $this->assertTrue($actual);

        $actual = $manager->get('test', null, true);
        $this->assertEquals($expected, $actual);

        $actual = $manager->has('test');
        $this->assertFalse($actual);

        $name     = uniqid();
        $expected = $name;
        $actual   = $manager->get('test', $name);
        $this->assertEquals($expected, $actual);

        $manager->destroy();

        $actual = $manager->exists();
        $this->assertFalse($actual);
    }
}
