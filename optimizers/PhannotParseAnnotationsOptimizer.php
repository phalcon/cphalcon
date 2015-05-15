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
use Zephir\HeadersManager;

class PhannotParseAnnotationsOptimizer extends OptimizerAbstract
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

		if (count($expression['parameters']) != 3) {
			throw new CompilerException("phannot_parse_annotations only accepts three parameter", $expression);
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

		$context->headersManager->add('phalcon/annotations/scanner', HeadersManager::POSITION_LAST);
		$context->headersManager->add('phalcon/annotations/annot', HeadersManager::POSITION_LAST);

		$symbolVariable->setDynamicTypes('array');

		$resolvedParams = $call->getResolvedParams($expression['parameters'], $context, $expression);

		$call->addCallStatusFlag($context);

		$context->codePrinter->output('ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(' . $symbolVariable->getName() . ', ' . $resolvedParams[0] . ', ' . $resolvedParams[1] . ', ' . $resolvedParams[2] . ' TSRMLS_CC);');

		$call->checkTempParameters($context);
		$call->addCallStatusOrJump($context);

		return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
	}

}
