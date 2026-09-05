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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class PreloadTest extends AbstractUnitTestCase
{
    /**
     * With a container holding a response the href is still given back, and
     * the Link header is set on the response.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testMvcViewEngineVoltPreloadWithContainer(): void
    {
        $container = new FactoryDefault();
        $volt      = new Volt(new View(), $container);

        $expected = 'abc.css';
        $actual   = $volt->preload('abc.css');
        $this->assertSame($expected, $actual);

        // setRawHeader() stores the whole line as the key with a null value
        $response = $container->get('response');
        $headers  = array_keys($response->getHeaders()->toArray());
        $joined   = implode("\n", $headers);

        $this->assertStringContainsString('Link:', $joined);
        $this->assertStringContainsString('abc.css', $joined);
    }
    /**
     * Without a container the href is given back untouched instead of
     * raising an error on the missing container.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testMvcViewEngineVoltPreloadWithoutContainer(): void
    {
        $volt = new Volt(new View());

        $expected = 'abc.css';
        $actual   = $volt->preload('abc.css');
        $this->assertSame($expected, $actual);
    }
}
