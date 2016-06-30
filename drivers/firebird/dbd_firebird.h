#ifndef __DBD_FIREBIRD_H
#define __DBD_FIREBIRD_H

typedef struct ibase_conn_s
{
  isc_db_handle db;             /* database handle */
  isc_tr_handle trans;          /* transaction handle */
  ISC_STATUS status_vector[ISC_STATUS_LENGTH];
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

#define FIREBIRD_CUSTOM_FUNCTIONS { \
     "isc_add_user", \
     "isc_array_get_slice", \
     "isc_array_lookup_bounds", \
     "isc_array_lookup_desc", \
     "isc_array_put_slice", \
     "isc_array_set_desc", \
     "isc_attach_database", \
     "isc_blob_default_desc", \
     "isc_blob_gen_bpb", \
     "isc_blob_info", \
     "isc_blob_lookup_desc", \
     "isc_blob_set_desc", \
     "isc_cancel_blob", \
     "isc_cancel_events", \
     "isc_close_blob", \
     "isc_commit_retaining", \
     "isc_commit_transaction", \
     "isc_create_blob2", \
     "isc_create_database", \
     "isc_database_info", \
     "isc_decode_sql_data", \
     "isc_decode_sql_time", \
     "isc_decode_timestamp", \
     "isc_delete_user", \
     "isc_detach_database", \
     "isc_drop_database", \
     "isc_dsql_allocate_statement", \
     "isc_dsql_alloc_statement2", \
     "isc_dsql_describe", \
     "isc_dsql_describe_bind", \
     "isc_dsql_execute", \
     "isc_dsql_execute2", \
     "isc_dsql_execute_immediate", \
     "isc_dsql_exec_immed2", \
     "isc_dsql_fetch", \
     "isc_dsql_free_statement", \
     "isc_dsql_prepare", \
     "isc_dsql_set_cursor_name", \
     "isc_dsql_sql_info", \
     "isc_encode_sql_date", \
     "isc_encode_sql_time", \
     "isc_encode_timestamp", \
     "isc_event_block", \
     "isc_event_counts", \
     "isc_expand_dpb", \
     "isc_get_segment", \
     "isc_interprete", \
     "isc_modify_user", \
     "isc_open_blob2", \
     "isc_prepare_transaction", \
     "isc_prepare_transaction2", \
     "isc_print_sqlerror", \
     "isc_print_status", \
     "isc_put_segment", \
     "isc_que_events", \
     "isc_rollback_retaining", \
     "isc_rollback_transaction", \
     "isc_service_attach", \
     "isc_service_detach", \
     "isc_service_query", \
     "isc_service_start", \
     "isc_sqlcode", \
     "isc_sql_interprete", \
     "isc_start_multiple", \
     "isc_start_transaction", \
     "isc_transaction_info", \
     "isc_vax_integer", \
     "isc_version", \
     "isc_wait_for_event", \
      NULL}

#endif /* __DBD_FIREBIRD_H */
