<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompilerException;
use Zephir\CompiledExpression;
use Zephir\Optimizers\OptimizerAbstract;

class PhalconEscapeCssOptimizer extends OptimizerAbstract
{

	/**
	 *
	 * @param array $expression
	 * @param Call $call
	 * @param CompilationContext $context
	 */
	public function optimize(array $expression, Call $call, CompilationContext $context)
	{

		if (!isset($expression['parameters'])) {
			return false;
		}

		if (count($expression['parameters']) != 1) {
			throw new CompilerException("phalcon_escape_css only accepts one parameter", $expression);
		}

		/**
		 * Process the expected symbol to be returned
		 */
		$call->processExpectedReturn($context);

		$symbolVariable = $call->getSymbolVariable();
		if ($symbolVariable->getType() != 'variable') {
			throw new CompilerException("Returned values by functions can only be assigned to variant variables", $expression);
		}

		if ($call->mustInitSymbolVariable()) {
			$symbolVariable->initVariant($context);
		}

		$context->headersManager->add('kernel/filter');

		$resolvedParams = $call->getResolvedParams($expression['parameters'], $context, $expression);
		$context->codePrinter->output('zephir_escape_css(' . $symbolVariable->getName() . ', ' . $resolvedParams[0] . ');');
		return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
	}

}
