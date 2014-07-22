#ifndef __DBD_FIREBIRD_H
#define __DBD_FIREBIRD_H

	
typedef struct ibase_conn_s
{
  isc_db_handle db;             /* database handle */
  isc_tr_handle trans;          /* transaction handle */
  ISC_STATUS_ARRAY status;
  const char *charset;
} ibase_conn_t;

typedef struct ibase_stmt_s
{
  XSQLDA  *osqlda;                 /* output SQLDA */
  isc_stmt_handle stmt;            /* statement handle */
  unsigned long long rowcount;
} ibase_stmt_t;

typedef struct vary_s {
  short vary_length;
  char vary_string[1];
} vary_t;


#define MAXLEN 1024

#ifndef ISC_INT64_FORMAT
#   define ISC_INT64_FORMAT        "ll"
#endif


#define FIREBIRD_RESERVED_WORDS \
{ \
     "ACTION", \
     "ACTIVE", \
     "ADD", \
     "ADMIN", \
     "AFTER", \
     "ALL", \
     "ALTER", \
     "AND", \
     "ANY", \
     "ARE", \
     "AS", \
     "ASC", \
     "ASCENDING", \
     "AT", \
     "AUTO", \
     "AUTODDL", \
     "AVG", \
     "BASED", \
     "BASENAME", \
     "BASE_NAME", \
     "BEFORE", \
     "BEGIN", \
     "BETWEEN", \
     "BLOB", \
     "BLOBEDIT", \
     "BUFFER", \
     "BY", \
     "CACHE", \
     "CASCADE", \
     "CAST", \
     "CHAR", \
     "CHARACTER", \
     "CHAR_LENGTH", \
     "CHARACTER_LENGTH", \
     "CHECK", \
     "CHECK_POINT_LEN", \
     "CHECK_POINT_LENGTH", \
     "CLOSE", \
     "COLLATE", \
     "COLLATION", \
     "COLUMN", \
     "COMMIT", \
     "COMMITTED", \
     "COMPILETIME", \
     "COMPUTED", \
     "CONDITIONAL", \
     "CONNECT", \
     "CONSTRAINT", \
     "CONTAINING", \
     "CONTINUE", \
     "COUNT", \
     "CREATE", \
     "CSTRING", \
     "CURRENT", \
     "CURRENT_DATE", \
     "CURRENT_TIME", \
     "CURRENT_TIMESTAMP", \
     "DATABASE", \
     "DATE", \
     "DAY", \
     "DB_KEY", \
     "DEBUG", \
     "DEC", \
     "DECIMAL", \
     "DECLARE", \
     "DEFAULT", \
     "DELETE", \
     "DESCENDING", \
     "DESCRIBE", \
     "DESCRIPTOR", \
     "DISCONNECT", \
     "DISPLAY", \
     "DISTINCT", \
     "DO", \
     "DOMAIN", \
     "DOUBLE",\
     "DROP",\
     "ECHO", \
     "EDIT", \
     "ELSE", \
     "END", \
     "ENTRY_POINT", \
     "ESCAPE", \
     "EVENT", \
     "EXCEPTION", \
     "EXEC", \
     "EXECUTE", \
     "EXISTS", \
     "EXIT", \
     "EXTERN", \
     "EXTERNAL", \
     "EXTRACT", \
     "FETCH", \
     "FILE", \
     "FILTER", \
     "FLOAT", \
     "FOR", \
     "FOREIGN", \
     "FOUND", \
     "FREE_IT", \
     "FROM", \
     "FULL", \
     "FUNCTION", \
     "GDSCODE", \
     "GENERATOR", \
     "GEN_ID", \
     "GLOBAL", \
     "GOTO", \
     "GRANT", \
     "GROUP", \
     "GROUP_COMMIT_WAIT", \
     "GROUP_COMMIT_WAIT_TIME", \
     "HAVING", \
     "HELP", \
     "HOUR", \
     "IF", \
     "IMMEDIATE", \
     "IN", \
     "INACTIVE", \
     "INDEX", \
     "INDICATOR", \
     "INNER", \
     "INPUT", \
     "INPUT_TYPE", \
     "INSERT", \
     "INT", \
     "INTEGER", \
     "INTO", \
     "IS", \
     "ISOLATION", \
     "ISQL", \
     "JOIN", \
     "KEY", \
     "LC_MESSAGES",\
     "LC_TYPE", \
     "LEFT", \
     "LENGTH", \
     "LEV", \
     "LEVEL", \
     "LIKE", \
     "LOGFILE", \
     "LOG_BUF_SIZE", \
     "LONG", \
     "MANUAL", \
     "MAX", \
     "MAXIMUM", \
     "MAXIMUM_SEGMENT", \
     "MAX_SEGMENT", \
     "MERGE", \
     "MESSAGE", \
     "MIN", \
     "MINIMUM", \
     "MINUTE", \
     "MODULE_NAME", \
     "MONTH", \
     "NAMES", \
     "NATIONAL", \
     "NATURAL", \
     "NCHAR", \
     "NO", \
     "NOAUTO", \
     "NOT", \
     "NULL", \
     "NUM_LOG_BUFS", \
     "NUM_LOG_BUFFERS", \
     "NUMERIC", \
     "OCTET_LENGTH", \
     "OF", \
     "ON", \
     "ONLY", \
     "OPEN", \
     "OPTION", \
     "OR", \
     "ORDER", \
     "OUTER", \
     "OUTPUT", \
     "OUTPUT_TYPE", \
     "OVERFLOW", \
     "PAGE", \
     "PAGELENGTH", \
     "PAGES", \
     "PAGE_SIZE", \
     "PARAMETER", \
     "PASSWORD", \
     "PLAN", \
     "POSITION", \
     "POST_EVENT", \
     "PRECISION", \
     "PREPARE", \
     "PRIMARY", \
     "PRIVILEGES", \
     "PROCEDURE", \
     "PUBLIC", \
     "QUIT", \
     "RAW_PARTITIONS", \
     "RDB$DB_KEY", \
     "READ", \
     "REAL", \
     "RECORD_VERSION", \
     "REFERENCES", \
     "RELEASE", \
     "RESERV", \
     "RESERVING", \
     "RESTRICT", \
     "RETAIN", \
     "RETURN", \
     "RETURNING_VALUES", \
     "RETURNS", \
     "REVOKE", \
     "RIGHT", \
     "ROLE", \
     "ROLLBACK", \
     "RUNTIME", \
     "SCHEMA", \
     "SECOND", \
     "SELECT", \
     "SET", \
     "SHADOW", \
     "SHARED", \
     "SHELL", \
     "SHOW", \
     "SINGULAR", \
     "SIZE", \
     "SMALLINT", \
     "SNAPSHOT", \
     "SOME", \
     "SORT", \
     "SQL", \
     "SQLCODE", \
     "SQLERROR", \
     "SQLWARNING", \
     "STABILITY", \
     "STARTING", \
     "STARTS", \
     "STATEMENT", \
     "STATIC", \
     "STATISTICS", \
     "SUB_TYPE", \
     "SUM", \
     "SUSPEND", \
     "TABLE", \
     "TERMINATOR", \
     "THEN", \
     "TIME", \
     "TIMESTAMP", \
     "TO", \
     "TRANSACTION", \
     "TRANSLATE", \
     "TRANSLATION", \
     "TRIGGER", \
     "TRIM", \
     "TRUE", \
     "TYPE", \
     "UNCOMMITTED", \
     "UNION", \
     "UNIQUE", \
     "UPDATE", \
     "UPPER", \
     "USER", \
     "USING", \
     "VALUE", \
     "VALUES", \
     "VARCHAR", \
     "VARIABLE", \
     "VARYING", \
     "VERSION", \
     "VIEW", \
     "WAIT", \
     "WEEKDAY", \
     "WHEN", \
     "WHENEVER", \
     "WHERE", \
     "WHILE", \
     "WITH", \
     "WORK", \
     "WRITE", \
     "YEAR", \
     "YEARDAY", \
     NULL \
}

#endif /* __DBD_FIREBIRD_H */
