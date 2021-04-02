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
use Zephir\HeadersManager;
use Zephir\Optimizers\OptimizerAbstract;

class PhqlParsePhqlOptimizer extends OptimizerAbstract
{
    /**
     * @param array              $expression
     * @param Call               $call
     * @param CompilationContext $context
     *
     * @return bool|CompiledExpression
     * @throws CompilerException
     */
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters'])) {
            return false;
        }

        if (count($expression['parameters']) != 1) {
            throw new CompilerException(
                "'phql_parse_phql' only accepts one parameter",
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

        $symbolVariable->setDynamicTypes('array');

        $resolvedParams = $call->getReadOnlyResolvedParams(
            $expression['parameters'],
            $context,
            $expression
        );

        $context->headersManager->add(
            'phalcon/mvc/model/query/scanner',
            HeadersManager::POSITION_LAST
        );

        $context->headersManager->add(
            'phalcon/mvc/model/query/phql',
            HeadersManager::POSITION_LAST
        );

        $call->addCallStatusFlag($context);

        $symbol = $context->backend->getVariableCode($symbolVariable);

        $context->codePrinter->output(
            'ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(' . $symbol . ', ' . $resolvedParams[0] . ');'
        );

        $call->checkTempParameters($context);
        $call->addCallStatusOrJump($context);

        return new CompiledExpression(
            'variable',
            $symbolVariable->getRealName(),
            $expression
        );
    }
}
