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

namespace Phalcon\Tests\Unit\Flash\Session;

use Phalcon\Flash\Session;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function ob_end_clean;
use function ob_get_contents;
use function ob_start;
use function uniqid;

use const PHP_EOL;

final class OutputTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionOutput(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $flash->clear();

        ob_start();
        $flash->output();
        $result = ob_get_contents();
        ob_end_clean();

        $this->assertEmpty($result);

        $session->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionOutputTypes(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '<div class="successMessage">' . $message1 . '</div>' . PHP_EOL
            . '<div class="errorMessage">' . $message2 . '</div>' . PHP_EOL;
        $this->assertSame($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';
        $this->assertSame($expected, $actual);

        $session->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-06-21
     */
    public function testFlashSessionOutputWithCustomTemplate(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1       = uniqid('m-');
        $customTemplate = "
<div class='%cssClass%' role='alert'>
    <button type='button' class='close' data-dismiss='alert' aria-label='Close'>
        <span aria-hidden='true'>&times;</span>
    </button>
    %message%
</div>";

        $flash->setCustomTemplate($customTemplate);

        $flash->success($message1);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = "
<div class='successMessage' role='alert'>
    <button type='button' class='close' data-dismiss='alert' aria-label='Close'>
        <span aria-hidden='true'>&times;</span>
    </button>
    {$message1}
</div>";
        $this->assertSame($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';
        $this->assertSame($expected, $actual);

        $session->destroy();
    }
}
