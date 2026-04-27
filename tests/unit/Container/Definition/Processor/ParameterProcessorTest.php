<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Definition\Processor;

use Phalcon\Container\Definition\DefinitionType;
use Phalcon\Container\Definition\Processor\ParameterProcessor;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Fake\FakeContainer;
use stdClass;

final class ParameterProcessorTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorCanProcessAlwaysReturnsTrue(): void
    {
        $processor = new ParameterProcessor();

        $this->assertTrue($processor->canProcess('string'));
        $this->assertTrue($processor->canProcess(42));
        $this->assertTrue($processor->canProcess(3.14));
        $this->assertTrue($processor->canProcess(true));
        $this->assertTrue($processor->canProcess(null));
        $this->assertTrue($processor->canProcess([]));
        $this->assertTrue($processor->canProcess(new stdClass()));
        $this->assertTrue($processor->canProcess(static function () {
        }));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorProcessClosureIsNotCacheable(): void
    {
        $processor = new ParameterProcessor();
        $closure   = static function () {
            return 42;
        };

        $def = $processor->process('factory', $closure, new FakeContainer());
        $def->freeze(new FakeContainer());

        $this->assertFalse($def->isCacheable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorProcessObjectIsNotCacheable(): void
    {
        $processor = new ParameterProcessor();
        $instance  = new stdClass();

        $def = $processor->process('obj', $instance, new FakeContainer());
        $def->freeze(new FakeContainer());

        $this->assertFalse($def->isCacheable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorProcessReturnsCorrectType(): void
    {
        $processor = new ParameterProcessor();

        $def = $processor->process('appName', 'MyApp', new FakeContainer());

        $this->assertSame(DefinitionType::DEF_PARAMETER, $def->getType());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorProcessScalarIsCacheable(): void
    {
        $processor = new ParameterProcessor();
        $container = new FakeContainer();

        $defString = $processor->process('appName', 'MyApp', $container);
        $defInt    = $processor->process('port', 8080, $container);
        $defBool   = $processor->process('debug', true, $container);
        $defArray  = $processor->process('config', ['a' => 1], $container);

        $defString->freeze($container);
        $this->assertTrue($defString->isCacheable());

        $defInt->freeze($container);
        $this->assertTrue($defInt->isCacheable());

        $defBool->freeze($container);
        $this->assertTrue($defBool->isCacheable());

        $defArray->freeze($container);
        $this->assertTrue($defArray->isCacheable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionProcessorParameterProcessorProcessSetsServiceName(): void
    {
        $processor = new ParameterProcessor();

        $def = $processor->process('appName', 'MyApp', new FakeContainer());

        $this->assertSame('appName', $def->getServiceName());
    }
}
