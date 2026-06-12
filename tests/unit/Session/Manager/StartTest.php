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
use Phalcon\Tests\Unit\Session\Fake\FakeManagerHeadersSent;

final class StartTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionManagerStartHeadersSent(): void
    {
        $manager = new FakeManagerHeadersSent();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->start();
        $this->assertFalse($actual);

        $manager->destroy();
    }

    /**
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionManagerStartInvalidCookieValueRemoved(): void
    {
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        if ($manager->exists()) {
            $manager->destroy();
        }

        $name           = $manager->getName();
        $_COOKIE[$name] = 'invalid<value>';

        $actual = $manager->start();
        $this->assertTrue($actual);

        $this->assertArrayNotHasKey($name, $_COOKIE);

        $manager->destroy();
    }

    /**
     * Session IDs may contain `,` and `-` depending on
     * session.sid_bits_per_character - the cookie must survive start()
     *
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionManagerStartSidAlphabetCookieValueKept(): void
    {
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        if ($manager->exists()) {
            $manager->destroy();
        }

        $name           = $manager->getName();
        $value          = 'abc,DEF-123';
        $_COOKIE[$name] = $value;

        $actual = $manager->start();
        $this->assertTrue($actual);

        $this->assertArrayHasKey($name, $_COOKIE);
        $this->assertSame($value, $_COOKIE[$name]);

        $manager->destroy();
        unset($_COOKIE[$name]);
    }
}
