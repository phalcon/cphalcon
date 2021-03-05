<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Exception\CompilerException;
use Zephir\Optimizers\OptimizerAbstract;

/**
 * Zephir\Optimizers\FunctionCall\PhalconEscapeCssOptimizer
 *
 * @package Zephir\Optimizers\FunctionCall
 */
class PhalconEscapeCssOptimizer extends OptimizerAbstract
{
    /**
     * @param array              $expression
     * @param Call               $call
     * @param CompilationContext $context
     *
     * @return bool|CompiledExpression
     *
     * @throws CompilerException
     */
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters'])) {
            return false;
        }

        if (count($expression['parameters']) != 1) {
            throw new CompilerException(
                "phalcon_escape_css only accepts one parameter",
                $expression
            );
        }

        /**
         * Process the expected symbol to be returned
         */
        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable();

        if ($symbolVariable->getType() != 'variable') {
            throw new CompilerException(
                "Returned values by functions can only be assigned to variant variables",
                $expression
            );
        }

        if ($call->mustInitSymbolVariable()) {
            $symbolVariable->initVariant($context);
        }

        $context->headersManager->add('kernel/filter');

        $resolvedParams = $call->getResolvedParams(
            $expression['parameters'],
            $context,
            $expression
        );

        $context->codePrinter->output(
            'zephir_escape_css(' . $symbolVariable->getName() . ', ' . $resolvedParams[0] . ');'
        );

        return new CompiledExpression(
            'variable',
            $symbolVariable->getRealName(),
            $expression
        );
    }
}
